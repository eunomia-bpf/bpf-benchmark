#ifndef BPFREJIT_SHIM_JSON_H
#define BPFREJIT_SHIM_JSON_H

#define JSMN_STATIC
#include "jsmn.h"

static int json_parse_alloc(const char *json, jsmntok_t **tokens_out, int *count_out) {
    *tokens_out = NULL;
    *count_out = 0;
    jsmn_parser parser;
    jsmn_init(&parser);
    int n = jsmn_parse(&parser, json, strlen(json), NULL, 0);
    if (n < 0) return -1;
    jsmntok_t *tokens = (jsmntok_t *)calloc((size_t)n ? (size_t)n : 1, sizeof(*tokens));
    if (!tokens) return -1;
    jsmn_init(&parser);
    int rc = jsmn_parse(&parser, json, strlen(json), tokens, (unsigned int)n);
    if (rc < 0) { free(tokens); return -1; }
    *tokens_out = tokens;
    *count_out = rc;
    return 0;
}

static int json_token_eq(const char *json, const jsmntok_t *tok, const char *s) {
    size_t n = strlen(s);
    return tok->type == JSMN_STRING && tok->start >= 0 && tok->end >= tok->start &&
           (size_t)(tok->end - tok->start) == n &&
           strncmp(json + tok->start, s, n) == 0;
}

static int json_skip_token(const jsmntok_t *tokens, int count, int idx) {
    if (idx < 0 || idx >= count) return count;
    int end = tokens[idx].end;
    int i = idx + 1;
    while (i < count && tokens[i].start >= 0 && tokens[i].start < end) i++;
    return i;
}

static int json_obj_get_tok(const char *json, const jsmntok_t *tokens, int count,
                            int obj_idx, const char *key) {
    if (obj_idx < 0 || obj_idx >= count || tokens[obj_idx].type != JSMN_OBJECT)
        return -1;
    int i = obj_idx + 1;
    for (int seen = 0; seen < tokens[obj_idx].size && i < count; seen++) {
        int key_idx = i;
        int val_idx = key_idx + 1;
        if (val_idx >= count) return -1;
        if (json_token_eq(json, &tokens[key_idx], key)) return val_idx;
        i = json_skip_token(tokens, count, val_idx);
    }
    return -1;
}

static int json_decode_string_token(const char *json, const jsmntok_t *tok,
                                    char *out, size_t out_sz) {
    if (tok->type != JSMN_STRING || out_sz == 0) return 0;
    const char *p = json + tok->start;
    const char *end = json + tok->end;
    size_t i = 0;
    while (p < end && i + 1 < out_sz) {
        if (*p == '\\' && p + 1 < end) {
            char c = 0;
            switch (p[1]) {
            case '"': c = '"'; break;
            case '\\': c = '\\'; break;
            case '/': c = '/'; break;
            case 'b': c = '\b'; break;
            case 'f': c = '\f'; break;
            case 'n': c = '\n'; break;
            case 'r': c = '\r'; break;
            case 't': c = '\t'; break;
            case 'u': {
                if (p + 5 < end) {
                    unsigned v = 0;
                    for (int k = 0; k < 4; k++) {
                        char h = p[2 + k];
                        v <<= 4;
                        if (h >= '0' && h <= '9') v |= (unsigned)(h - '0');
                        else if (h >= 'a' && h <= 'f') v |= (unsigned)(10 + h - 'a');
                        else if (h >= 'A' && h <= 'F') v |= (unsigned)(10 + h - 'A');
                        else { v = 0; break; }
                    }
                    out[i++] = (char)(v & 0xff);
                    p += 6;
                    continue;
                }
                c = 'u';
                break;
            }
            default: c = p[1]; break;
            }
            out[i++] = c;
            p += 2;
            continue;
        }
        out[i++] = *p++;
    }
    out[i] = 0;
    return 1;
}

static long json_get_int(const char *json, const char *key) {
    jsmntok_t *tokens = NULL;
    int count = 0;
    if (json_parse_alloc(json, &tokens, &count) != 0 || count <= 0) return -1;
    int val_idx = json_obj_get_tok(json, tokens, count, 0, key);
    long out = -1;
    if (val_idx >= 0 && tokens[val_idx].start >= 0 && tokens[val_idx].end >= tokens[val_idx].start) {
        size_t n = (size_t)(tokens[val_idx].end - tokens[val_idx].start);
        if (n > 0 && n < 32) {
            char buf[32];
            memcpy(buf, json + tokens[val_idx].start, n);
            buf[n] = 0;
            char *endp = NULL;
            long v = strtol(buf, &endp, 10);
            if (endp && *endp == 0) out = v;
        }
    }
    free(tokens);
    return out;
}

static const char *json_array_at(const char *json, const char *key,
                                 const char **end_out) {
    jsmntok_t *tokens = NULL;
    int count = 0;
    if (json_parse_alloc(json, &tokens, &count) != 0 || count <= 0) return NULL;
    int val_idx = json_obj_get_tok(json, tokens, count, 0, key);
    const char *start = NULL;
    if (val_idx >= 0 && tokens[val_idx].type == JSMN_ARRAY) {
        int s = tokens[val_idx].start;
        int e = tokens[val_idx].end;
        if (s >= 0 && e > s) {
            start = json + s;
            const char *end = json + e;
            if (*start == '[') start++;
            if (end > json && end[-1] == ']') end--;
            if (end_out) *end_out = end;
        }
    }
    free(tokens);
    return start;
}

static int json_array_next_obj(const char **cursor, const char *array_end,
                               const char **obj_start, const char **obj_end) {
    const char *c = *cursor;
    while (c < array_end &&
           (*c == ' ' || *c == ',' || *c == '\n' || *c == '\t' || *c == '\r'))
        c++;
    if (c >= array_end || *c != '{') return 0;
    *obj_start = c;
    int depth = 1, in_str = 0;
    c++;
    while (c < array_end && depth > 0) {
        if (*c == '\\' && c + 1 < array_end) { c += 2; continue; }
        if (*c == '"') { in_str = !in_str; c++; continue; }
        if (!in_str) {
            if (*c == '{') depth++;
            else if (*c == '}') depth--;
        }
        c++;
    }
    *obj_end = c;
    *cursor = c;
    return 1;
}

static int json_get_str(const char *json, const char *key, char *out,
                        size_t out_sz) {
    jsmntok_t *tokens = NULL;
    int count = 0;
    if (json_parse_alloc(json, &tokens, &count) != 0 || count <= 0) return 0;
    int val_idx = json_obj_get_tok(json, tokens, count, 0, key);
    int ok = 0;
    if (val_idx >= 0) ok = json_decode_string_token(json, &tokens[val_idx], out, out_sz);
    free(tokens);
    return ok;
}

/* JSON-escape `raw` of length `n` into `out` (size out_sz). Truncates to fit;
 * always NUL-terminates. Drops control chars below 0x20 except \n \r \t.
 * Encodes non-ASCII bytes (>=0x80) as \uXXXX to keep the output pure ASCII —
 * verifier logs frequently contain stray high bytes (pointer formatting,
 * truncated register-state dumps) that would otherwise produce invalid
 * UTF-8 and break JSON parsing on the runner side. */
static void json_escape_into(const char *raw, size_t n, char *out, size_t out_sz) {
    size_t o = 0;
    for (size_t i = 0; i < n && o + 8 < out_sz; i++) {
        unsigned char c = (unsigned char)raw[i];
        if (c == '"' || c == '\\') { out[o++] = '\\'; out[o++] = c; }
        else if (c == '\n') { out[o++] = '\\'; out[o++] = 'n'; }
        else if (c == '\r') { out[o++] = '\\'; out[o++] = 'r'; }
        else if (c == '\t') { out[o++] = '\\'; out[o++] = 't'; }
        else if (c >= 0x20 && c < 0x7f) out[o++] = (char)c;
        else if (c >= 0x80) {
            /* \uXXXX (6 chars). Need room. */
            if (o + 6 >= out_sz) break;
            static const char hex[] = "0123456789abcdef";
            out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
            out[o++] = hex[(c >> 4) & 0xf]; out[o++] = hex[c & 0xf];
        }
        /* drop other control chars 0x00-0x1f except \n\r\t */
    }
    out[o < out_sz ? o : out_sz - 1] = 0;
}

/* Read the tail of `path` (up to 1024 bytes), JSON-escape, store into `out`. */
static void read_tail_escaped(const char *path, char *out, size_t out_sz) {
    out[0] = 0;
    int lfd = open(path, O_RDONLY);
    if (lfd < 0) return;
    struct stat st;
    if (fstat(lfd, &st) == 0 && st.st_size > 0) {
        off_t off = st.st_size > 1024 ? st.st_size - 1024 : 0;
        lseek(lfd, off, SEEK_SET);
        char raw[1025];
        ssize_t n = read(lfd, raw, sizeof(raw) - 1);
        if (n > 0) json_escape_into(raw, (size_t)n, out, out_sz);
    }
    real_close(lfd);
}

/* Append printf-style content to a growing heap buffer. Returns 0 on success,
 * -1 on OOM (in which case *buf is freed). */
static int buf_appendf(char **buf, size_t *cap, size_t *len, const char *fmt, ...) {
    for (;;) {
        va_list ap;
        va_start(ap, fmt);
        int n = vsnprintf(*buf + *len, *cap - *len, fmt, ap);
        va_end(ap);
        if (n < 0) return -1;
        if ((size_t)n < *cap - *len) { *len += (size_t)n; return 0; }
        size_t want = *cap * 2;
        if (want < *cap + (size_t)n + 1) want = *cap + (size_t)n + 1;
        char *nr = (char *)realloc(*buf, want);
        if (!nr) { free(*buf); *buf = NULL; return -1; }
        *buf = nr;
        *cap = want;
    }
}

#endif /* BPFREJIT_SHIM_JSON_H */

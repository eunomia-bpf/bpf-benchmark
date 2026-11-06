/* Reference output from the unchanged native scale fixture on the real CPU. */
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct native_context { unsigned char *data, *data_end; };
extern uint64_t entry(struct native_context *context);

int main(int argc, char **argv)
{
    if (argc!=2) { fprintf(stderr,"usage: native-scale-probe INPUT_BYTE\n"); return 1; }
    char *end;
    errno=0;
    unsigned long value=strtoul(argv[1],&end,10);
    if (errno || end==argv[1] || *end || value>255) { fprintf(stderr,"invalid input byte\n"); return 1; }
    unsigned char data[64];
    memset(data,1,sizeof(data));
    memset(data,0,8);
    data[8]=(unsigned char)value;
    struct native_context context={data,data+sizeof(data)};
    uint64_t retval=entry(&context), result;
    memcpy(&result,data,sizeof(result));
    printf("{\"result\":%" PRIu64 ",\"retval\":%" PRIu64 "}\n",result,retval);
    if (fflush(stdout)) { perror("write native scale output"); return 1; }
    return retval!=2;
}

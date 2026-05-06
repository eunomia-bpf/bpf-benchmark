# Rotate Offline Capture Check - 2026-05-06

## 001. Verdict

001. Finding A is confirmed for this run.
002. The run did not leave usable captured rotate bytecode on the host.
003. I could not run the offline rotate matcher on daemon-fed bytecode because no `captured-input-rotate.bin` was exported.
004. The stronger observation is that the rotate command recorded in the result was never capture-wrapped.
005. The captured run has 38 Cilium rotate pass records.
006. All 38 records use the plain `timeout 600 bpfopt --pass rotate ...` command.
007. Zero records contain `cp ${INPUT}`.
008. Zero records contain `captured-input-rotate.bin`.
009. Zero records contain `&& false`.
010. The result tree contains no `details/failure-artifacts/` directory.
011. The app JSON contains no `workdir_tar_b64` field.
012. The suite result JSON contains no `workdir_tar_b64` field.
013. The app JSON contains no `failure_artifacts` field.
014. The suite result JSON contains no `failure_artifacts` field.
015. The run therefore does not answer whether daemon-fed Cilium bytecode has rotate sites.
016. It only shows that the debug capture/export path did not execute as intended.
017. The immediate next step is to make the capture preflight observable before spending another corpus run.
018. Specifically, verify inside the exact runtime image/VM that `build_step_spec("rotate", ...)` emits the `cp ... captured-input-rotate.bin && ... && false` command under `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS=1`.
019. Also pass/verify `--keep-failure-artifacts`, because the runner consumes daemon `workdir_tar_b64` responses and writes them to files only when `failure_artifacts_dir` is non-null.
020. This run should not be used as evidence for finding B or C.

## 002. Investigated Inputs

021. Main smoke result: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json`.
022. App detail result: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json`.
023. Run metadata: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json`.
024. Daemon logs: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/daemon.stdout.log`.
025. Daemon logs: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/daemon.stderr.log`.
026. Source checked for expected capture behavior: `runner/libs/rejit_plan.py`.
027. Source checked for artifact persistence behavior: `runner/libs/rejit.py`.
028. Source checked for corpus artifact directory wiring: `corpus/driver.py`.
029. Source checked for suite argument wiring: `runner/suites/corpus.py`.
030. Source checked for runtime env pass-through: `runner/suites/_common.py`.
031. Source checked for runtime container env pass-through: `runner/libs/suite_commands.py`.
032. Source checked for daemon workdir tar generation: `daemon/src/commands.rs`.
033. No daemon was spawned during this investigation.
034. No new corpus run was started during this investigation.
035. No files under `vendor/linux-framework/` were read or modified.
036. Host-side `bpfopt` was not invoked because there were zero captured bytecode inputs.
037. The only repo write from this task is this report.

## 003. Result Tree Inventory

038. `find` found only three directories under the run root.
039. Directory: `corpus/results/x86_kvm_corpus_20260506_074857_891000`.
040. Directory: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details`.
041. Directory: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps`.
042. There is no `details/failure-artifacts` directory.
043. There is no app-specific artifact directory under `details/apps`.
044. There is no tarball file under the run root.
045. There is no extracted `captured-input-rotate.bin` under the run root.
046. File inventory:
047. `59617` bytes: `details/apps/cilium__agent.json`.
048. `0` bytes: `details/daemon.stderr.log`.
049. `71` bytes: `details/daemon.stdout.log`.
050. `103` bytes: `details/progress.json`.
051. `70884` bytes: `details/result.json`.
052. `638` bytes: `metadata.json`.
053. `daemon.stdout.log` contains only daemon lifecycle lines.
054. It says the daemon listened on `/var/tmp/bpfrejit-daemon.sock` at line 1.
055. It says the daemon shut down at line 2.
056. `daemon.stderr.log` is empty.
057. There is no daemon-side line naming a retained workdir.
058. There is no daemon-side line naming a tar export.

## 004. Run Metadata Evidence

059. The metadata says the enabled pass set was rotate only.
060. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:3`.
061. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:4`.
062. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:5`.
063. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:6`.
064. The metadata identifies this as an `x86_kvm_corpus` run.
065. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:15`.
066. The metadata says `samples` was 1.
067. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:16`.
068. The metadata start time was `2026-05-06T07:48:57.891000+00:00`.
069. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:17`.
070. The metadata status was `completed`.
071. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:18`.
072. The metadata workload length was 3 seconds.
073. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/metadata.json:20`.
074. Metadata does not record whether `--keep-failure-artifacts` was passed.
075. Metadata does not record the value of `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS`.
076. Therefore, artifact-directory presence is the host-side evidence for preservation.

## 005. Suite Result Evidence

077. The suite result used daemon binary `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`.
078. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:2`.
079. The suite result was generated at `2026-05-06T07:49:27.936021+00:00`.
080. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:3`.
081. The expected kinsn modules included `bpf_rotate`.
082. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:7`.
083. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:12`.
084. The module load snapshot included `bpf_rotate`.
085. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:16`.
086. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:21`.
087. The loaded module list included `bpf_rotate`.
088. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:27`.
089. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:32`.
090. The raw `lsmod` output included `bpf_rotate`.
091. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:57`.
092. The single result entry is `cilium/agent`.
093. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:103`.
094. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/result.json:105`.
095. The kinsn environment was not the cause of missing artifacts.
096. The rotate module was resident before the app result was recorded.

## 006. App Result Evidence

097. The app JSON contains a `rejit_result` object.
098. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:714`.
099. The top-level ReJIT error is only prog 11 permission denied.
100. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:715`.
101. The `per_program` object begins at line 716.
102. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:716`.
103. Program 10's rotate summary says `sites_matched: 0`.
104. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:726`.
105. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:727`.
106. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:728`.
107. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:729`.
108. Program 10's rotate step status is `ok`.
109. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:732`.
110. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:733`.
111. Program 10's command is the plain rotate command.
112. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:734`.
113. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:735`.
114. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:736`.
115. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:737`.
116. Program 11's rotate summary also says zero matched/applied/skipped.
117. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:756`.
118. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:761`.
119. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:762`.
120. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:763`.
121. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:764`.
122. Program 11 failed during ReJIT, not during bpfopt.
123. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:767`.
124. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:768`.
125. Program 11's command is also the plain rotate command.
126. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:769`.
127. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:770`.
128. The final program, prog 106, also records the plain rotate command.
129. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:1990`.
130. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:1992`.
131. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:1993`.
132. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:1994`.
133. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:1995`.
134. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:1996`.
135. Prog 106 is `cil_to_host` and has program type 3.
136. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2000`.
137. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2005`.
138. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2006`.
139. The app-level `rejit_result.status` is `error`.
140. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2011`.
141. The app runner is `cilium`.
142. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2013`.
143. The selected workload is `network_lossy_multi`.
144. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2014`.
145. The app status is still `ok`.
146. Evidence: `corpus/results/x86_kvm_corpus_20260506_074857_891000/details/apps/cilium__agent.json:2015`.

## 007. Structured JSON Checks

147. `jq '[.. | objects | has("workdir_tar_b64")] | map(select(.)) | length'` returned `0` for the app JSON.
148. The same command returned `0` for the suite result JSON.
149. `jq '[.. | objects | has("failure_artifacts")] | map(select(.)) | length'` returned `0` for the app JSON.
150. The same command returned `0` for the suite result JSON.
151. Searching JSON paths for `workdir` returned no app JSON path.
152. Searching JSON paths for `artifact` returned no app JSON path.
153. Searching JSON paths for `captured` returned no app JSON path.
154. Searching JSON paths for `failure` returned no app JSON path.
155. Searching JSON paths for `tar` returned no app JSON path.
156. Searching JSON paths for `b64` returned no app JSON path.
157. The suite result JSON had `captured_at` kinsn metadata paths only.
158. Those paths are module snapshot timestamps, not workdir capture artifacts.
159. The app JSON has 38 rotate records.
160. The app JSON has one command variant.
161. The single command variant is `timeout 600 bpfopt --pass rotate --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE} --target ${TARGET}`.
162. The app JSON has 37 rotate records with status `ok`.
163. The app JSON has 1 rotate record with status `failed_rejit`.
164. The app JSON has total `sites_matched` sum 0.
165. The app JSON has total `sites_applied` sum 0.
166. The app JSON has total `sites_skipped` sum 0.
167. Counting rotate commands containing `captured-input-rotate.bin` returned 0.
168. Counting rotate commands containing `&& false` returned 0.
169. Counting rotate commands containing `cp ${INPUT}` returned 0.
170. Therefore the command-generation side of capture did not show up in the recorded result.

## 008. Per-Program Rotate Records

171. Columns: prog_id, pass_status, insn_count_before, matched, applied, skipped.
172. `10`, `ok`, `35`, `0`, `0`, `0`.
173. `11`, `failed_rejit`, `65`, `0`, `0`, `0`.
174. `67`, `ok`, `1194`, `0`, `0`, `0`.
175. `69`, `ok`, `489`, `0`, `0`, `0`.
176. `70`, `ok`, `2`, `0`, `0`, `0`.
177. `71`, `ok`, `1110`, `0`, `0`, `0`.
178. `72`, `ok`, `227`, `0`, `0`, `0`.
179. `73`, `ok`, `70`, `0`, `0`, `0`.
180. `74`, `ok`, `96`, `0`, `0`, `0`.
181. `75`, `ok`, `227`, `0`, `0`, `0`.
182. `76`, `ok`, `1194`, `0`, `0`, `0`.
183. `77`, `ok`, `351`, `0`, `0`, `0`.
184. `78`, `ok`, `96`, `0`, `0`, `0`.
185. `79`, `ok`, `70`, `0`, `0`, `0`.
186. `81`, `ok`, `2`, `0`, `0`, `0`.
187. `83`, `ok`, `1194`, `0`, `0`, `0`.
188. `84`, `ok`, `351`, `0`, `0`, `0`.
189. `85`, `ok`, `70`, `0`, `0`, `0`.
190. `86`, `ok`, `96`, `0`, `0`, `0`.
191. `87`, `ok`, `2`, `0`, `0`, `0`.
192. `88`, `ok`, `227`, `0`, `0`, `0`.
193. `89`, `ok`, `489`, `0`, `0`, `0`.
194. `90`, `ok`, `1110`, `0`, `0`, `0`.
195. `91`, `ok`, `70`, `0`, `0`, `0`.
196. `92`, `ok`, `227`, `0`, `0`, `0`.
197. `93`, `ok`, `489`, `0`, `0`, `0`.
198. `94`, `ok`, `1110`, `0`, `0`, `0`.
199. `95`, `ok`, `96`, `0`, `0`, `0`.
200. `96`, `ok`, `2`, `0`, `0`, `0`.
201. `97`, `ok`, `1194`, `0`, `0`, `0`.
202. `98`, `ok`, `351`, `0`, `0`, `0`.
203. `99`, `ok`, `96`, `0`, `0`, `0`.
204. `100`, `ok`, `227`, `0`, `0`, `0`.
205. `102`, `ok`, `70`, `0`, `0`, `0`.
206. `103`, `ok`, `2`, `0`, `0`, `0`.
207. `104`, `ok`, `1194`, `0`, `0`, `0`.
208. `105`, `ok`, `1110`, `0`, `0`, `0`.
209. `106`, `ok`, `351`, `0`, `0`, `0`.
210. This table is from `cilium__agent.json` via `jq`.
211. It confirms the user-observed smoke result: rotate matched 0 across all Cilium programs.
212. It does not validate the daemon-fed bytecode shape because no captured bytecode was exported.

## 009. Expected Capture Wrapper

213. Current `runner/libs/rejit_plan.py` builds the normal bpfopt command first.
214. Evidence: `runner/libs/rejit_plan.py:65`.
215. Evidence: `runner/libs/rejit_plan.py:66`.
216. Evidence: `runner/libs/rejit_plan.py:67`.
217. Evidence: `runner/libs/rejit_plan.py:68`.
218. Evidence: `runner/libs/rejit_plan.py:69`.
219. Evidence: `runner/libs/rejit_plan.py:70`.
220. Evidence: `runner/libs/rejit_plan.py:71`.
221. Evidence: `runner/libs/rejit_plan.py:72`.
222. For target-needing passes such as rotate, it appends `--target ${TARGET}`.
223. Evidence: `runner/libs/rejit_plan.py:74`.
224. Evidence: `runner/libs/rejit_plan.py:75`.
225. The current capture patch then joins the command.
226. Evidence: `runner/libs/rejit_plan.py:82`.
227. The capture path is gated by `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS`.
228. Evidence: `runner/libs/rejit_plan.py:83`.
229. Evidence: `runner/libs/rejit_plan.py:88`.
230. Evidence: `runner/libs/rejit_plan.py:89`.
231. When that env var is non-empty, the command is rewritten.
232. Evidence: `runner/libs/rejit_plan.py:90`.
233. The rewritten command should copy `${INPUT}` to `${WORKDIR}/captured-input-<pass>.bin`.
234. Evidence: `runner/libs/rejit_plan.py:91`.
235. The rewritten command should append the original command.
236. Evidence: `runner/libs/rejit_plan.py:92`.
237. The rewritten command should force failure with `&& false`.
238. Evidence: `runner/libs/rejit_plan.py:93`.
239. Evidence: `runner/libs/rejit_plan.py:94`.
240. The recorded result commands do not reflect lines 90-94.
241. Therefore either this source was not the source used in the runtime that generated the plan, or the env var was not present when the plan was built.
242. The result itself cannot distinguish stale runtime Python from missing env.

## 010. Env Pass-Through Checks

243. `runner/suites/_common.py` copies `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` into the runtime env if it is set.
244. Evidence: `runner/suites/_common.py:188`.
245. Evidence: `runner/suites/_common.py:202`.
246. Evidence: `runner/suites/_common.py:206`.
247. Evidence: `runner/suites/_common.py:209`.
248. `runner/libs/suite_commands.py` also allows the same env var through to the runtime container command.
249. Evidence: `runner/libs/suite_commands.py:17`.
250. Evidence: `runner/libs/suite_commands.py:20`.
251. This source-level pass-through makes a missing top-level env value or stale runtime image the most likely explanations.
252. It does not prove which one happened in the completed run.
253. The completed run metadata did not record enough launcher env or argv detail to disambiguate.

## 011. Failure Artifact Pipeline Checks

254. The daemon result type has an optional `workdir_tar_b64` field.
255. Evidence: `daemon/src/commands.rs:118`.
256. Evidence: `daemon/src/commands.rs:124`.
257. Evidence: `daemon/src/commands.rs:126`.
258. Evidence: `daemon/src/commands.rs:127`.
259. The daemon has a helper that runs `tar -czf - -C <workdir> .`.
260. Evidence: `daemon/src/commands.rs:320`.
261. Evidence: `daemon/src/commands.rs:321`.
262. Evidence: `daemon/src/commands.rs:322`.
263. Evidence: `daemon/src/commands.rs:323`.
264. Evidence: `daemon/src/commands.rs:324`.
265. Evidence: `daemon/src/commands.rs:325`.
266. The daemon base64-encodes the tar output.
267. Evidence: `daemon/src/commands.rs:334`.
268. The daemon sets `workdir_tar_b64` when a result status is not ok or any pass status is not ok.
269. Evidence: `daemon/src/commands.rs:490`.
270. Evidence: `daemon/src/commands.rs:491`.
271. Evidence: `daemon/src/commands.rs:492`.
272. Evidence: `daemon/src/commands.rs:493`.
273. Evidence: `daemon/src/commands.rs:494`.
274. Evidence: `daemon/src/commands.rs:495`.
275. Evidence: `daemon/src/commands.rs:496`.
276. Evidence: `daemon/src/commands.rs:497`.
277. The daemon also tars the workdir on an error path.
278. Evidence: `daemon/src/commands.rs:501`.
279. Evidence: `daemon/src/commands.rs:502`.
280. Evidence: `daemon/src/commands.rs:503`.
281. The runner removes `workdir_tar_b64` from each daemon per-program record before storing the result dict.
282. Evidence: `runner/libs/rejit.py:419`.
283. Evidence: `runner/libs/rejit.py:420`.
284. Evidence: `runner/libs/rejit.py:421`.
285. Evidence: `runner/libs/rejit.py:422`.
286. Therefore `workdir_tar_b64` is not expected to survive into `cilium__agent.json`.
287. The runner writes the tar to disk only when `failure_artifacts_dir` is non-null.
288. Evidence: `runner/libs/rejit.py:236`.
289. Evidence: `runner/libs/rejit.py:241`.
290. Evidence: `runner/libs/rejit.py:245`.
291. Evidence: `runner/libs/rejit.py:246`.
292. Evidence: `runner/libs/rejit.py:247`.
293. Evidence: `runner/libs/rejit.py:248`.
294. Evidence: `runner/libs/rejit.py:249`.
295. Evidence: `runner/libs/rejit.py:250`.
296. Corpus runner passes `failure_artifacts_dir` into `apply_rejit`.
297. Evidence: `corpus/driver.py:576`.
298. Evidence: `corpus/driver.py:577`.
299. Evidence: `corpus/driver.py:578`.
300. Evidence: `corpus/driver.py:579`.
301. `failure_artifacts_dir` is set to `details/failure-artifacts` only when `args.keep_failure_artifacts` is true.
302. Evidence: `corpus/driver.py:702`.
303. Evidence: `corpus/driver.py:704`.
304. Evidence: `corpus/driver.py:705`.
305. Evidence: `corpus/driver.py:706`.
306. Evidence: `corpus/driver.py:707`.
307. The suite wrapper adds `--keep-failure-artifacts` only when `args.keep_failure_artifacts` is true.
308. Evidence: `runner/suites/corpus.py:66`.
309. Evidence: `runner/suites/corpus.py:68`.
310. Evidence: `runner/suites/corpus.py:69`.
311. Since this run has a real failed ReJIT pass for prog 11, a preserved artifact directory would be expected if `--keep-failure-artifacts` was active and the daemon binary matched current behavior.
312. No such directory exists in the result tree.
313. This is a second export-path failure independent of the missing capture command wrapper.

## 012. Why Offline bpfopt Was Not Run

314. The requested offline command needs one or more captured bytecode files.
315. The expected filename was `captured-input-rotate.bin`.
316. No such file exists under the result directory.
317. No tarball exists under the result directory from which such a file can be extracted.
318. No `workdir_tar_b64` payload exists in JSON to decode manually.
319. The runner source explains why JSON absence alone is not decisive: the field is popped before storage.
320. The directory absence is decisive for host-available artifacts.
321. Running `bpfopt --pass rotate --input <bytecode> ...` on no inputs would produce no useful evidence.
322. I therefore did not run host-side `bpfopt`.
323. This avoids accidentally substituting static object bytecode for daemon-fed bytecode.
324. It also preserves the core distinction this investigation was meant to test.

## 013. Root-Cause Assessment

325. Confirmed root cause for this task: capture/export did not produce host-available daemon-fed bytecode.
326. More precise sub-finding 1: rotate commands were not capture-wrapped.
327. More precise sub-finding 2: no failure artifact directory was preserved.
328. The missing wrapper means `cp ${INPUT} ${WORKDIR}/captured-input-rotate.bin` did not run for any of the 38 rotate records.
329. The missing wrapper also means the intended `&& false` did not force bpfopt-step failure.
330. Without forced step failure, the 37 otherwise-ok programs had no reason to tar their workdirs.
331. Prog 11 did fail, but at ReJIT, and still no host tar directory is present.
332. That points to missing `--keep-failure-artifacts`, stale runner/daemon behavior, or both.
333. The result command evidence rules out finding C for this run.
334. There is no captured bytecode on which matcher correctness could have been proven.
335. The result command evidence also prevents finding B for this run.
336. There is no daemon-fed bytecode sample showing rotate matched 0 offline.
337. The existing matched=0 summaries remain real pipeline observations.
338. They are not yet explained by bytecode shape versus result propagation.

## 014. Recommended Next Step

339. Do a preflight before the next capture run.
340. Use the same runtime image/VM path that will execute the corpus.
341. Set `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS=1`.
342. Import `runner.libs.rejit_plan`.
343. Call `build_step_spec("rotate", {"needs_target": True})`.
344. Assert the command contains `captured-input-rotate.bin`.
345. Assert the command contains `&& false`.
346. Assert the command starts with `cp ${INPUT} ${WORKDIR}/captured-input-rotate.bin`.
347. Fail immediately if the preflight prints the plain `timeout 600 bpfopt ...` command.
348. Also verify the launched corpus argv contains `--keep-failure-artifacts`.
349. After the run starts, inspect the first app JSON command before waiting for the whole suite if possible.
350. If using Docker/VM images, rebuild or refresh the Python/runtime layer after staging `runner/libs/rejit_plan.py`.
351. Do not rely on the daemon env var name alone; current daemon `WorkDir::drop` removes workdirs unconditionally.
352. Evidence: `daemon/src/commands.rs:83`.
353. Evidence: `daemon/src/commands.rs:84`.
354. Evidence: `daemon/src/commands.rs:85`.
355. Evidence: `daemon/src/commands.rs:90`.
356. The env var is only meaningful here because `rejit_plan.py` checks it during command construction.
357. If the next run produces tars, extract all `captured-input-rotate.bin` files and then run the requested offline `bpfopt --pass rotate` loop.
358. If that offline loop matches >0, continue with daemon invocation/result propagation.
359. If that offline loop matches 0, continue with live-bytecode shape analysis.
360. For this completed run, stop at finding A.

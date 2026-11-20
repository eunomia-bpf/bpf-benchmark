import KProgFormal.ClightRefinement.Arm64CacheLocalFrame

open KProgFormal.ClightRefinement

#check Arm64CacheLocalFrame.Kept.trans
#print axioms Arm64CacheLocalFrame.Kept.trans

#check Arm64CacheLocalFrame.of_frame
#print axioms Arm64CacheLocalFrame.of_frame

#check Arm64CacheLocalFrame.Kept.pointers
#print axioms Arm64CacheLocalFrame.Kept.pointers

#check Arm64CacheLocalFrame.borrowed_load
#print axioms Arm64CacheLocalFrame.borrowed_load

#check Arm64CacheLocalFrame.Kept.borrowed
#print axioms Arm64CacheLocalFrame.Kept.borrowed

#check Arm64CacheLocalFrame.Kept.warm
#print axioms Arm64CacheLocalFrame.Kept.warm

#check Arm64CacheLocalFrame.warm_iff
#print axioms Arm64CacheLocalFrame.warm_iff

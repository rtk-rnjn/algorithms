# Interleaving String

from __future__ import annotations


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1_len = len(s1)
        s2_len = len(s2)
        s3_len = len(s3)
        if s1_len + s2_len != s3_len:
            return False

        s1_count = 0
        s2_count = 0
        s3_count = 0

        while s3_count < s3_len:
            if s1_count < s1_len and s1[s1_count] == s3[s3_count]:
                s1_count += 1
            elif s2_count < s2_len and s2[s2_count] == s3[s3_count]:
                s2_count += 1
            else:
                return False
            s3_count += 1

        return True

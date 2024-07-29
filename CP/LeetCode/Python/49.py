# 49. Group Anagram

from __future__ import annotations


class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagrams: dict[tuple[str, ...], list[str]] = {}
        for s in strs:
            key = tuple(sorted(s))
            if key in anagrams:
                anagrams[key].append(s)
            else:
                anagrams[key] = [s]
        return list(anagrams.values())


if __name__ == "__main__":
    solution = Solution()

    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(solution.groupAnagrams(strs))
    # Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    strs = [""]
    print(solution.groupAnagrams(strs))
    # Output: [[""]]

    strs = ["a"]
    print(solution.groupAnagrams(strs))
    # Output: [["a"]]

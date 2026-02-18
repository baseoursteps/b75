# An attempt at LC's Blind 75 Questions

## Array

1. [~~Two sum~~](src/001tsum.cc)

   Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

   You may assume that each input would have exactly one solution, and you may not use the same element twice.

   You can return the answer in any order.

2. [(!)~~Best time to buy and sell stock~~](src/002stonks.cc)

   You are given an array prices where prices[i] is the price of a given stock on the ith day.

   You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

   Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

3. [~~Contains duplicate~~](3dup.cpp)
4. [(!)~~Product of array except self~~](4prod.cpp)
5. [~~Maximum Subarray~~](5max.cpp)
6. [(!)~~Maximum Product Subarray~~](6prod.cpp)
7. [~~Find Minimum in Rotated Sorted Array~~](7rot.cpp)
8. [~~Search in Rotated Sorted Array~~](8find.cpp)
9. [(!)~~3 sum~~](9sum.cpp)
10. [(!)~~Container With Most Water~~](10water.cpp)


## Binary

11. [~~Sum of Two Integers~~](11sum.cpp)
12. [~~Number of 1 Bits~~](12hamming.cpp)
13. [(?)~~Counting Bits~~](13cb.cpp)
14. [(?)~~Missing Number~~](14miss.cpp)
15. [~~Reverse Bits~~](15rev.cpp)

## DP

16. [~~Climbing Stairs~~](16st.cpp)
17. [~~Coin Change~~](17c.cpp)
18. [~~Longest Increasing Subsequence~~](18lis.cpp)
19. [~~Longest Common Subsequence~~](19lcs.cpp)
20. [(!)~~Word Break Problem~~](20wb.cpp)
21. [(!)~~Combination Sum~~](21cs.cpp)
22. [~~House Robber~~](22hr.cpp)
23. [~~House Robber II~~](23hr2.cpp)
24. [~~Decode Ways~~](24dw.cpp)
25. [~~Unique Paths~~](25up.cpp)
26. [~~Jump Game~~](26jmp.cpp)

## Graph

27. [~~Clone Graph~~](27clone.cpp)
28. [~~Course Schedule~~](28course.cpp)
29. [~~Pacific Atlantic Water Flow~~](29water.cpp)
30. [~~Number of Islands~~](30islands.cpp)
31. [~~Longest Consecutive Sequence~~](31seq.cpp)
32. [(!)~~Alien Dictionary~~](32alien.cpp)
33. [(!)~~Graph Valid Tree~~](33validt.cpp)
34. [~~Number of Connected Components in an Undirected Graph~~](34comp.cpp)

## Interval

35. [~~Insert Interval~~](35ii.cpp)
36. [~~Merge Intervals~~](36merge.cpp)
37. [~~Non-overlapping Intervals~~](37non.cpp)
38. [~~Meeting Rooms (Leetcode Premium)~~](38mr.cpp)
39. [~~Meeting Rooms II(Leetcode Premium)~~](39mr2.cpp)

## Lists

40. [~~Reverse a Linked List~~](40rev.cpp)
41. [~~Detect Cycle in a Linked List~~](41cycle.cpp)
42. [~~Merge Two Sorted Lists~~](src/042merge.cc)

    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

43. [~~Merge K Sorted Lists~~](43merge.cpp)
44. [~~Remove Nth Node From End Of List~~](44end.cpp)
45. [(!)~~Reorder List~~](45reorder.cpp)

## Matrix

46. [(!)~~Set Matrix Zeroes~~](46zeros.cpp)
47. [~~Spiral Matrix~~](47spiral.cpp)
48. [(!)~~Rotate Image~~](48turn.cpp)
49. [~~Word Search~~](49word.cpp)

## String

50. [~~Longest Substring Without Repeating Characters~~](50ls.cpp)
51. [~~Longest Repeating Character Replacement~~](51lc.cpp)
52. [~~Minimum Window Substring~~](52wnd.cpp)
53. [~~Valid Anagram~~](src/053ana.cc)

    Given two strings s and t, return true if t is an of s, and false otherwise.

    An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

54. [~~Group Anagrams~~](54ga.cpp)
55. [~~Valid Parentheses~~](src/055par.cc)

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

        - Open brackets must be closed by the same type of brackets.
        - Open brackets must be closed in the correct order.
        - Every close bracket has a corresponding open bracket of the same type.

56. [~~Valid Palindrome~~](src/056pdrome.cc)

    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

57. [(?)~~Longest Palindromic Substring~~](57lpal.cpp)
58. [~~Palindromic Substrings~~](58nps.cpp)
59. [~~Encode and Decode Strings~~](59ende.cpp)

## Tree

60. [~~Maximum Depth of Binary Tree~~](60depth.cpp)
61. [~~Same Tree~~](61same.cpp)
62. [~~Invert/Flip Binary Tree~~](src/062invert.cc)

    Given the root of a binary tree, invert the tree, and return its root.

63. [~~Binary Tree Maximum Path Sum~~](63psum.cpp)
64. [~~Binary Tree Level Order Traversal~~](64level.cpp)
65. [~~Serialize and Deserialize Binary Tree~~](65codec.cpp)
66. [~~Subtree of Another Tree~~](66subtree.cpp)
67. [(!)~~Construct Binary Tree from Preorder and Inorder Traversal~~](67build.cpp)
68. [~~Validate Binary Search Tree~~](68valid.cpp)
69. [~~Kth Smallest Element in a BST~~](69kth.cpp)
70. [~~Lowest Common Ancestor of a BST~~](src/070lca.cc)

    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

71. [~~Implement Trie (Prefix Tree)~~](71trie.cpp)
72. [~~Add and Search Word~~](72trie.cpp)
73. [(!)~~Word Search II~~](73words.cpp)

## Heap

74. [~~Merge K Sorted Lists~~](74merge.cpp)
75. [~~Top K Frequent Elements~~](75kfreq.cpp)
76. [(!)~~Find Median from Data Stream~~](76median.cpp)

[Source](https://medium.com/@miniChang8/75-leetcode-must-know-questions-953b3749c7e9)

## Misc and Grind75

77. [~~Convert BST to doubly-linked list in-place~~](77bst.cpp)
78. Longest path cost in binary tree, then normalise all the other paths
79. [~~Flood Fill~~](src/079ff.cc)

    You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

    To perform a flood fill:

        - Begin with the starting pixel and change its color to color.
        - Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
        - Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
        - The process stops when there are no more adjacent pixels of the original color to update.

    Return the modified image after performing the flood fill.

80. [~~Balanced Binary Tree~~](src/080bt.cc)

    Given a binary tree, determine if it is height-balanced.

    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

81. [~~Implement Queue Using Stacks~~](81qs.cpp)
82. [~~First Bad Version~~](82fbv.cpp)
83. [~~Ransom Note~~](83ran.cpp)
84. [~~Majority Element~~](84me.cpp)
85. [~~Diameter of Binary Tree~~](85dbt.cpp)
86. [~~Middle of Linked List~~](86mid.cpp)
87. [(!)~~01 Matrix~~](87m.cpp)
88. [~~K Closest Points to Origin~~](88k.cpp)
89. [~~Binary Tree Level Order Traversal~~](89lot.cpp)
90. [~~Evaluate RPN~~](90rpn.cpp)
91. [(!)~~Course Schedule~~](91cs.cpp)
92. [~~Min Stack~~](92ms.cpp)
93. [~~Rotting Oranges~~](93ro.cpp)
94. [(!)~~Permutations~~](94perm.cpp)
95. [~~Time-based Key-Value Store~~](95tmap.cpp)
96. [(!)~~Accounts Merge~~](96am.cpp)
97. [~~Sort Colors~~](97sc.cpp)
98. [(!)~~Partition Equal Subset Sum~~](98pess.cpp)
99. [~~String to Integer (atoi)~~](99atoi.cpp)
100. [(!)~~Subsets~~](100ss.cpp)
101. [~~Binary Tree Right-side View~~](101rsv.cpp)
102. [(!)~~Letter Combinations of a Phone Number~~](102pn.cpp)
103. [(!)~~Find All Anagrams in a String~~](103ana.cpp)
104. [(!)~~Minimum Height Trees~~](104ht.cpp)
105. [(!)~~Task Scheduler~~](105ts.cpp)
106. [(!)~~LRU Cache~~](106lru.cpp)
107. [(!)~~Trapping Rain Water~~](107trp.cpp)
108. [(!)~~Word Ladder~~](108wl.cpp)
109. [(!)~~Basic Calculator~~](109bc.cpp)
110. [(!?)~~Maximum Profit in Job Scheduling~~](110pft.cpp)
111. [(!)~~Largest Rectangle in Histogram~~](111hst.cpp)
112. [~~Reverse a Singly-Linked List Between Two Indices~~](112lst.cpp)
113. [~~Binary Search~~](src/113bsearch.cc)

    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

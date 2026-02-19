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

3. [~~Contains duplicate~~](src/003dup.cc)

    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

4. [(!)~~Product of array except self~~](src/4prod.cpp)
5. [~~Maximum Subarray~~](src/5max.cpp)
6. [(!)~~Maximum Product Subarray~~](src/6prod.cpp)
7. [~~Find Minimum in Rotated Sorted Array~~](src/7rot.cpp)
8. [~~Search in Rotated Sorted Array~~](src/8find.cpp)
9. [(!)~~3 sum~~](src/9sum.cpp)
10. [(!)~~Container With Most Water~~](src/10water.cpp)


## Binary

11. [~~Sum of Two Integers~~](src/11sum.cpp)
12. [~~Number of 1 Bits~~](src/12hamming.cpp)
13. [(?)~~Counting Bits~~](src/13cb.cpp)
14. [(?)~~Missing Number~~](src/14miss.cpp)
15. [~~Reverse Bits~~](src/15rev.cpp)

## DP

16. [~~Climbing Stairs~~](src/016st.cc)

    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

17. [~~Coin Change~~](src/17c.cpp)
18. [~~Longest Increasing Subsequence~~](src/18lis.cpp)
19. [~~Longest Common Subsequence~~](src/19lcs.cpp)
20. [(!)~~Word Break Problem~~](src/20wb.cpp)
21. [(!)~~Combination Sum~~](src/21cs.cpp)
22. [~~House Robber~~](src/22hr.cpp)
23. [~~House Robber II~~](src/23hr2.cpp)
24. [~~Decode Ways~~](src/24dw.cpp)
25. [~~Unique Paths~~](src/25up.cpp)
26. [~~Jump Game~~](src/26jmp.cpp)

## Graph

27. [~~Clone Graph~~](src/27clone.cpp)
28. [~~Course Schedule~~](src/28course.cpp)
29. [~~Pacific Atlantic Water Flow~~](src/29water.cpp)
30. [~~Number of Islands~~](src/30islands.cpp)
31. [~~Longest Consecutive Sequence~~](src/31seq.cpp)
32. [(!)~~Alien Dictionary~~](src/32alien.cpp)
33. [(!)~~Graph Valid Tree~~](src/33validt.cpp)
34. [~~Number of Connected Components in an Undirected Graph~~](src/34comp.cpp)

## Interval

35. [~~Insert Interval~~](src/35ii.cpp)
36. [~~Merge Intervals~~](src/36merge.cpp)
37. [~~Non-overlapping Intervals~~](src/37non.cpp)
38. [~~Meeting Rooms (Leetcode Premium)~~](src/38mr.cpp)
39. [~~Meeting Rooms II(Leetcode Premium)~~](src/39mr2.cpp)

## Lists

40. [~~Reverse a Linked List~~](src/040rev.cc)

    Given the head of a singly linked list, reverse the list, and return the reversed list.

41. [~~Detect Cycle in a Linked List~~](src/041cycle.cc)

    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.
42. [~~Merge Two Sorted Lists~~](src/042merge.cc)

    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

43. [~~Merge K Sorted Lists~~](src/43merge.cpp)
44. [~~Remove Nth Node From End Of List~~](src/44end.cpp)
45. [(!)~~Reorder List~~](src/45reorder.cpp)

## Matrix

46. [(!)~~Set Matrix Zeroes~~](src/46zeros.cpp)
47. [~~Spiral Matrix~~](src/47spiral.cpp)
48. [(!)~~Rotate Image~~](src/48turn.cpp)
49. [~~Word Search~~](src/49word.cpp)

## String

50. [~~Longest Substring Without Repeating Characters~~](src/50ls.cpp)
51. [~~Longest Repeating Character Replacement~~](src/51lc.cpp)
52. [~~Minimum Window Substring~~](src/52wnd.cpp)
53. [~~Valid Anagram~~](src/053ana.cc)

    Given two strings s and t, return true if t is an of s, and false otherwise.

    An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

54. [~~Group Anagrams~~](src/54ga.cpp)
55. [~~Valid Parentheses~~](src/055par.cc)

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
      - Open brackets must be closed by the same type of brackets.
      - Open brackets must be closed in the correct order.
      - Every close bracket has a corresponding open bracket of the same type.

56. [~~Valid Palindrome~~](src/056pdrome.cc)

    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

57. [(?)~~Longest Palindromic Substring~~](src/57lpal.cpp)
58. [~~Palindromic Substrings~~](src/58nps.cpp)
59. [~~Encode and Decode Strings~~](src/59ende.cpp)

## Tree

60. [~~Maximum Depth of Binary Tree~~](src/060depth.cc)

    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

61. [~~Same Tree~~](src/61same.cpp)
62. [~~Invert/Flip Binary Tree~~](src/062invert.cc)

    Given the root of a binary tree, invert the tree, and return its root.

63. [~~Binary Tree Maximum Path Sum~~](src/63psum.cpp)
64. [~~Binary Tree Level Order Traversal~~](src/64level.cpp)
65. [~~Serialize and Deserialize Binary Tree~~](src/65codec.cpp)
66. [~~Subtree of Another Tree~~](src/66subtree.cpp)
67. [(!)~~Construct Binary Tree from Preorder and Inorder Traversal~~](src/67build.cpp)
68. [~~Validate Binary Search Tree~~](src/68valid.cpp)
69. [~~Kth Smallest Element in a BST~~](src/69kth.cpp)
70. [~~Lowest Common Ancestor of a BST~~](src/070lca.cc)

    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

71. [~~Implement Trie (Prefix Tree)~~](src/71trie.cpp)
72. [~~Add and Search Word~~](src/72trie.cpp)
73. [(!)~~Word Search II~~](src/73words.cpp)

## Heap

74. [~~Merge K Sorted Lists~~](src/74merge.cpp)
75. [~~Top K Frequent Elements~~](src/75kfreq.cpp)
76. [(!)~~Find Median from Data Stream~~](src/76median.cpp)

[Source](https://medium.com/@miniChang8/75-leetcode-must-know-questions-953b3749c7e9)

## Misc and Grind75

77. [~~Convert BST to doubly-linked list in-place~~](src/77bst.cpp)
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

81. [~~Implement Queue Using Stacks~~](src/081qs.cc)

    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:
      - void push(int x) Pushes element x to the back of the queue.
      - int pop() Removes the element from the front of the queue and returns it.
      - int peek() Returns the element at the front of the queue.
      - boolean empty() Returns true if the queue is empty, false otherwise.

82. [~~First Bad Version~~](src/082fbv.cc)

    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

83. [~~Ransom Note~~](src/083ran.cc)

    Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

    Each letter in magazine can only be used once in ransomNote.

84. [~~Majority Element~~](src/84me.cpp)
85. [~~Diameter of Binary Tree~~](src/85dbt.cpp)
86. [~~Middle of Linked List~~](src/86mid.cc)

    Given the head of a singly linked list, return the middle node of the linked list.

    If there are two middle nodes, return the second middle node.

87. [(!)~~01 Matrix~~](src/87m.cpp)
88. [~~K Closest Points to Origin~~](src/88k.cpp)
89. [~~Binary Tree Level Order Traversal~~](src/89lot.cpp)
90. [~~Evaluate RPN~~](src/90rpn.cpp)
91. [(!)~~Course Schedule~~](src/91cs.cpp)
92. [~~Min Stack~~](src/92ms.cpp)
93. [~~Rotting Oranges~~](src/93ro.cpp)
94. [(!)~~Permutations~~](src/94perm.cpp)
95. [~~Time-based Key-Value Store~~](src/95tmap.cpp)
96. [(!)~~Accounts Merge~~](src/96am.cpp)
97. [~~Sort Colors~~](src/97sc.cpp)
98. [(!)~~Partition Equal Subset Sum~~](src/98pess.cpp)
99. [~~String to Integer (atoi)~~](src/99atoi.cpp)
100. [(!)~~Subsets~~](src/100ss.cpp)
101. [~~Binary Tree Right-side View~~](src/101rsv.cpp)
102. [(!)~~Letter Combinations of a Phone Number~~](src/102pn.cpp)
103. [(!)~~Find All Anagrams in a String~~](src/103ana.cpp)
104. [(!)~~Minimum Height Trees~~](src/104ht.cpp)
105. [(!)~~Task Scheduler~~](src/105ts.cpp)
106. [(!)~~LRU Cache~~](src/106lru.cpp)
107. [(!)~~Trapping Rain Water~~](src/107trp.cpp)
108. [(!)~~Word Ladder~~](src/108wl.cpp)
109. [(!)~~Basic Calculator~~](src/109bc.cpp)
110. [(!?)~~Maximum Profit in Job Scheduling~~](src/110pft.cpp)
111. [(!)~~Largest Rectangle in Histogram~~](src/111hst.cpp)
112. [~~Reverse a Singly-Linked List Between Two Indices~~](src/112lst.cpp)
113. [~~Binary Search~~](src/113bsearch.cc)

     Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

     You must write an algorithm with O(log n) runtime complexity.

114. [~~Add Binary~~](src/114add.cc)

     Given two binary strings a and b, return their sum as a binary string.

# Code Signal
These are some random exercises pulled from [Code Signal](https://codesignal.com/developers/)

## RPG Game
You are playing an RPG game.  
Currently your experience points (XP) total is equal to experience.  
To reach the next level your XP should be at least at threshold.  
If you kill the monster in front of you, you will gain more experience points in the amount of the reward.  
Given values experience, threshold and reward, check if you reach the next level after killing the monster.  

## PEP 8
PEP 8, Style Guide for Python Code, requires a coder to write lines no longer than 79 characters.  
Given some code line, find out if it satisfies PEP 8 requirements.

## Cipher
You've intercepted an encrypted message, and you are really curious about its contents.  
You were able to find out that the message initially contained only lowercase English letters,  
and was encrypted with the following cipher:  
  Let all letters from 'a' to 'z' correspond to the numbers from 0 to 25, respectively.  
  The number corresponding to the ith letter of the encrypted message is then equal to the sum of numbers  
    corresponding to the first i letters of the initial unencrypted message modulo 26.  
Now that you know how the message was encrypted, implement the algorithm to decipher it.  
Example:  
  For message = "taiaiaertkixquxjnfxxdh", the output should be  
    cipher26(message) = "thisisencryptedmessage".  
The initial message "thisisencryptedmessage" was encrypted as follows:  
  letter 0: t -> 19 -> t;  
  letter 1: th -> (19 + 7) % 26 -> 0 -> a;  
  letter 2: thi -> (19 + 7 + 8) % 26 -> 8 -> i;  
  etc.  
    
## Power
Determine if the given number is a power of some non-negative integer

## Arrays
### First Duplicate
### First Not Repeating Character
Write a solution that only iterates over the string once and uses O(1) additional memory, since this is what you would 
be asked to do during a real interview.  
Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it.  
If there is no such character, return '_'.

## Trees
### Has Duplicate Subtree
Given a binary tree t, determine if there is a duplicate sub-tree

### Has Path With Given Sum
Given a binary tree t and an integer s, determine whether there is a root to leaf path in t such that the sum of vertex values equals s.

### Is Tree Symmetric
Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.

## Linked list
### Remove K From List
Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in the list, 
since this is what you'll be asked to do during an interview.  
Given a singly linked list of integers l and an integer k, remove all elements from list l that have a value equal to k.

### Is List Palindrome
Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is
what you'll be asked to do during an interview.  
Given a singly linked list of integers, determine whether or not it's a palindrome.

### Add Two Huge Numbers
You're given 2 huge integers represented by linked lists.  
Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits.  
The represented number might have leading zeros.  
Your task is to add up these huge integers and return the result in the same format.

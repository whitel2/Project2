# Project2

## Task 1: Git Repository and Collaboration
Add the professor as a collaborator\
Divide out tasks\
Create a branch for each person\
Notes:\
\
Error Checking: Test for merge conflicts before merging.\
Testing: Use a test driver in your branch for verifying individual components.

## Task 2: Lexicographical Sort
Use a Radix Sort with a queue to manage words during the sort process\
Write a function to sort the word list.\
Notes:\
\
Error Checking: Ensure input list is non-empty.\
Testing: Test with edge cases, e.g., sorted input, reverse-sorted input, single word.

## Task 3: Remove Duplicates
Write a function that removes duplicates from a sorted word list.\
Use a vector to manage words.\
Notes:\
\
Error Checking: Verify the input is sorted before deduplication.\
Testing: Test with lists containing:\
No duplicates.\
Some duplicates.\
All duplicates.

## Task 4: Find Valid Transformations
Develop a function to find all valid one-letter transformations.\
Use a dictionary look-up to validate words.\
Use a stack to trace back steps for transformations.\
Notes:\
\
Error Checking: Verify words are the same length. Check if dictionary data is available.\
Testing: Test with:\
Words with no valid transformations.\
Words with multiple transformations.

## Task 5: Solve the Problem
Develop a function to find a solution using valid transformations.\
Use a stack to store the sequence of transformations\
**Extra Credit: Use a queue for breadth-first search (BFS) to find the most efficient path.
Output each step/word and the total number of steps.\
Notes:\
\
Error Checking: Check that the start and target words are in the dictionary.\
Testing: Test with:\
Easy transformations (e.g., one step away).\
Challenging transformations (e.g., multiple steps with many choices).\
\
General Suggestions\
Testing Strategy:\
Test each function separately before committing\
Cover the following cases:\
Valid input (e.g., words in the dictionary).\
Invalid input (e.g., different word lengths, symbols).\
Edge cases (e.g., shortest possible path, no possible path).

# Maze-Solver

![BFS-Algorithm_Search_Way](https://user-images.githubusercontent.com/94260151/197352881-2ae45dd2-38b4-4a21-b4c0-4bc408ff5a4c.gif)


Program that finds the shortest path through a maze using a variation of the breadth-first-search algorithm

Here's what a sample text file of the nodes of a maze looks like:- 

<a href="https://drive.google.com/file/d/1srvrXOEKwaF9SunM0QWxNbO4INfowj6L/view" target="_blank"> Sample Text File </a>

![image](https://user-images.githubusercontent.com/94260151/197352564-5d06663f-dbc6-4933-a94a-f397cd2f0c10.png)

Here, the first line contains the point of entry, exit of the maze. The lines following that describe what each node in the maze connects to.

For example, node 3 connects to 2, 4, and 5 in this case. A -1 signifies the end of a line. 

The shortest path through this maze and it's associated cost is - 
Start -> 1 -> 2 -> 3 -> 5 -> 6 -> Exit

Total Cost: 6


Another maze example - 

<a href="https://drive.google.com/file/d/1Gb9pnA8EnKBR74rclH_hnopY5Dgd5uSt/view" target="_blank"> Another Maze File </a>

![image](https://user-images.githubusercontent.com/94260151/197353538-19a8884b-1bfd-4abd-9e52-7ea9079a17f4.png)

This one begins at 1 and ends at 50. The shortest path along with it's associated cost for this maze is: 

Start -> 1 -> 11 -> 21 -> 22 -> 32 -> 31 -> 41 -> 42 -> 43 -> 44 -> 34 -> 35 -> 25 -> 15 -> 14 -> 4 -> 5 -> 6 -> 16 -> 1
7 -> 7 -> 8 -> 9 -> 10 -> 20 -> 19 -> 29 -> 39 -> 38 -> 48 -> 49 -> 50 -> Exit

Total Cost: 33


Since the files contain information on what each node points to, we can even traverse the maze backwards! A solution for this would look like 

Start -> 50 -> 49 -> 48 -> 38 -> 39 -> 29 -> 19 -> 20 -> 10 -> 9 -> 8 -> 7 -> 17 -> 16 -> 6 -> 5 -> 4 -> 14 -> 15 -> 25
-> 35 -> 34 -> 44 -> 43 -> 42 -> 41 -> 31 -> 32 -> 22 -> 21 -> 11 -> 1 -> Exit

Total Cost: 33

Start -> 6 -> 5 -> 3 -> 2 -> 1 -> Exit

Total Cost: 6



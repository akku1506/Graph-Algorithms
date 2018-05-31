# Graph Algorithms
Codes available for various standard graph algorithms

## degree.cpp
It finds degree of vertices for a given undirected graph

Program take as input a text file which contains the input graph with the format shown as below. Output of the program should be degrees of all the vertices of the input graph as shown below.
	
	eg.
		Input file (input.txt)
		
		6,u
		a,b,c,d,e,f
		a,b
		d,e
		f,b
		b,e
		a,c
		c,d
		b,d


It represents an undirected graph with six (6) vertices specified in first line. The ID’s of vertices are a,b,...e,f mentioned in second line. Subsequently, each line specifies an edge with starting and ending vertices, respectively. Say, a,b on third line means an edge (a,b) in the graph and so on ... (total seven edges in the graph).


	Output file (output.txt)
		
		a 2
		b 4
		c 2
		d 3
		e 2
		f 1

It contains the ID’s of vertices, along with their respective degree in each line separated with a single space. 
			


	Sample Run: 
		It assumes that your program is compiled into vertexDegree.out executable and takes input.txt file as input and output.txt file as output.

		./vertexDegree.out input.txt output.txt	

## path.cpp 

It solves path existence problem in graph.

Program take as input a text file which contains the directed graph as input in the format as specified in the above question except that in this case the last line of input file contains the path whose existence is to be ascertained. Your program should ascertain whether the path specified in the last line of input file exist in the input graph or not.
	
	eg.
	  Input file (input.txt)

	4,d
	1,2,3,4
	1,2
	2,3
	1,4
	4,3
	1,4,3

It represents a directed graph with six (4) vertices specified in first line. The ID’s of vertices are 1,2,3,4 mentioned in second line. Subsequently, each line specifies an edge with starting and ending vertices, respectively. Say, 1,2 on third line means a directed edge (1,2) in the graph and so on ... (total four edges in the graph). It specifies the path 1,4,3 on the last line.


	Output file (output.txt)

		It contains 1 if path exists or 0 if it doesn’t exist. 
			
		1

	Sample Run: 
		It assumes that your program is compiled into pathExists.out executable and takes input.txt file as input and output.txt file as output.

	./pathExists.out input.txt output.txt	


## connectedComponents.cpp 

It finds connected components of a given undirected graph

Your program should take as input an input file which contains the input undirected graph. Program should output the connected components, each on separate line with vertices of connected component separated with comma.

	eg.
		Input file (input.txt)

		6,u
		a,b,c,d,e,f
		a,b
		c,b
		d,e
		f,f

		Output file (output.txt)
			
		a,b,c
		d,e
		f
		
Note: The vertices in connected component should be sorted with respect to their vertex ID. For example if vertices b, d and c are part of a connected component, then they should be output as b,c,d

In the output file above obtained from input file above, there are three connected components.
		

	Sample Run: 
	It assumes that your program is compiled into connectedComponents.out executable and takes input.txt file as input and output.txt file as output.

		./connectedComponents.out input.txt output.txt

## dfs.cpp 

It does depth first search on the graph

Program that takes a graph as input and outputs the vertices in the order in which they are discovered for the first time (discovery time when vertex becomes grey from white) when DFS is applied.

Note: The vertices in adjacency list should be sorted with respect to their vertex ID. For example if vertices b, d and c are adjacent to vertex a, then Adj[a] = {b,c,d} and not {b,d,c}.

	eg.
		Input file (input.txt)

		6,u
		a,b,c,d,e,f
		a,b
		a,c
		c,f
		b,d
		d,e
		e,f
		b,e

		Output file (output.txt)
				
		a,b,d,e,f,c

	Sample Run: 
		It assumes that your program is compiled into dfs.out executable and takes input.txt file as input and output.txt file as output.

		./dfs.out input.txt output.txt
## kruskal.cpp

It finds MST of a given graph using Kruskal’s algorithm.

Program take as input a text file which contains the weighted graph as input. Output of the program should be edges that part of MST, output each edge as it gets selected to be part of MST on a separate line.

	eg.
		Input file (input.txt)

		5,u
		a,b,c,d,e
		a,b,4
		b,c,8
		c,d,2
		d,e,7
		b,e,11
		e,a,6

First edge is from vertex a to b with weight 4 and so on ....

		Output file (output.txt)
		c,d
		a,b
		e,a
		d,e

It contains the edges that are part of MST, each edge on a separate line as it gets selected. 
Note: Carefully observe the order of vertices mentioned in the edge in output file is the same as mentioned in the input file.
		

	Sample Run: 
		It assumes that your program is compiled into kruskalMST.out executable and takes input.txt file as input and output.txt file as output.

		./kruskalMST.out input.txt output.txt		 	

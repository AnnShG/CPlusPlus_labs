#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
/*
1. Draw a graph consisting of 10 vertices on paper. At the vertices of the
		graph, write the letters that make up your surname and part of your name
2. Graph realization - Incidence matrix 
3. Traverse algorithm - Bypassing in width
4. read the text at the vertices of the graph.
5. Analyze the read text and put the letters on vertices in such a way that you
		can read the surname and first name correctly. 
		Go around the graph again, reading new text.

6. The technique of creating a graph and its bypass should be implemented in the program
7. Read text analysis and transposition of letters at the vertices of the graph 
		must be performed both within the program path.
*/

std::vector<std::vector<int>> incidence_matrix = { // is a two-dimensional vector that represents an incidence matrix of a graph
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10 vertices and 12 edges
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
};

// An unordered map is a container that stores key-value pairs in no particular order, providing fast access to individual elements by their key
std::unordered_map<int, char> vertex_labels = { // is a data structure with vertex_labels variable is an unordered map that associates each vertex index with a characters
    {0, 'S'},
    {1, 'H'},
    {2, 'K'},
    {3, 'A'},
    {4, 'E'},
    {5, 'V'},
    {6, 'A'},
    {7, 'A'},
    {8, 'N'},
    {9, 'N'}
};

void bfs(int start_vertex) { // Breadth-First Search on the graph starting from the vertex start_vertex
    // The purpose of the visited vector is to ensure that the BFS algorithm doesn't visit a vertex more than once,
    std::vector<bool> visited(10, false); // creates a vector of boolean values called visited. The vector is initialized with 10 elements, all set to false
    std::queue<int> q; // creates an empty queue of integers named q.This queue is used to manage the order of vertices to be visited during the BFS traversal of the graph.

    visited[start_vertex] = true; // sets the value in the visited vector at the position corresponding to start_vertex to true, indicating that the starting vertex has been visited.
    q.push(start_vertex); // adds the starting vertex to the queue q

    while (!q.empty()) { //  the loop continues until the queue q is empty, indicating that all reachable vertices have been visited.
        int current_vertex = q.front(); // retrieves the vertex at the front of the queue q without removing it. This is the next vertex to be processed in the BFS traversal.
        q.pop(); // removes the vertex at the front of the queue q, as it has been processed.

        std::cout << vertex_labels[current_vertex]; // prints the label of the current vertex, which corresponds to a character from the user's surname and part of their name.

        for (int edge = 0; edge < 12; ++edge) { // iterates over all the edges in the graph, represented by the columns in the incidence matrix
            if (incidence_matrix[current_vertex][edge] == 1) { // checks if the current vertex is connected to the current edge
                for (int vertex = 0; vertex < 10; ++vertex) { // iterates over all the vertices in the graph to find the other vertex connected to the current edge.
                    if (incidence_matrix[vertex][edge] == 1 && vertex != current_vertex && !visited[vertex]) { // checks if the vertex is connected to the current edge, is not the same as the current vertex, and has not been visited yet
                        visited[vertex] = true; // marks the vertex as visited in the visited vector.
                        q.push(vertex); // adds the vertex to the back of the queue q, ensuring that it will be visited in the BFS traversal.
                    }
                }
            }
        }
    }
}

int main() {
    int start_vertex = 0;
    bfs(start_vertex);
    std::cout << std::endl;

    return 0;
}

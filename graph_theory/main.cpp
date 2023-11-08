#include <bits/stdc++.h>
using namespace std;
 
// Below dfs function will be used to
// get the connected components of a
// graph and stores all the connected
// nodes in the vector component
void dfs(int src, vector<bool>& visited,
         vector<vector<int> >& graph,
         vector<int>& component, int N)
{
 
    // Mark this vertex as visited
    visited[src] = true;
 
    // Put this node in component vector
    component.push_back(src);
 
    // For all other vertices in graph
    for (int dest = 0; dest < N; dest++) {
 
        // If there is an edge between
        // src and dest i.e., the value
        // of graph[u][v]!=INT_MAX
        if (graph[src][dest] != INT_MAX) {
 
            // If we haven't visited dest
            // then recursively apply
            // dfs on dest
            if (!visited[dest])
                dfs(dest, visited, graph,
                    component, N);
        }
    }
}
 
// Below is the Floyd Warshall Algorithm
// which is based on Dynamic Programming
void floydWarshall(
    vector<vector<int> >& graph, int N)
{
 
    // For every vertex of graph find
    // the shortest distance with
    // other vertices
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
 
                // Taking care of integer
                // overflow
                if (graph[i][k] != INT_MAX
                    && graph[k][j] != INT_MAX) {
 
                    // Update distance between
                    // vertex i and j if choosing
                    // k as an intermediate vertex
                    // make a shorter distance
                    if (graph[i][k] + graph[k][j]
                        < graph[i][j])
                        graph[i][j]
                            = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
 
// Function to find the maximum shortest
// path distance in a component by checking
// the shortest distances between all
// possible pairs of nodes
int maxInThisComponent(vector<int>& component,
                       vector<vector<int> >& graph)
{
    int maxDistance = INT_MIN;
    int n = component.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            maxDistance
                = max(maxDistance,
                      graph[component[i]][component[j]]);
        }
    }
 
    // If the maxDistance is still INT_MIN
    // then return 0 because this component
    // has a single element
    return (maxDistance == INT_MIN
                ? 0
                : maxDistance);
}
 
// Below function uses above two method
// to get the  maximum shortest distances
// in each component of the graph the
// function returns a vector, where each
// element denotes maximum shortest path
// distance for a component
vector<int> maximumShortesDistances(
    vector<vector<int> >& graph, int N)
{
 
    // Find the connected components
    vector<bool> visited(N, false);
    vector<vector<int> > components;
 
    // For storing the nodes in a
    // particular component
    vector<int> temp;
 
    // Now for each unvisited node run
    // the dfs to get the connected
    // component having this unvisited node
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
 
            // First of all clear the temp
            temp.clear();
            dfs(i, visited, graph, temp, N);
            components.push_back(temp);
        }
    }
 
    // Now for all-pair find the shortest
    // path distances using Floyd Warshall
    floydWarshall(graph, N);
 
    // Now for each component find the
    // maximum shortest distance and
    // store it in result
    vector<int> result;
    int numOfComp = components.size();
    int maxDistance;
    for (int i = 0; i < numOfComp; i++) {
        maxDistance
            = maxInThisComponent(components[i], graph);
        result.push_back(maxDistance);
    }
    return result;
}
 
// Driver Code
int main()
{
    int N = 8;
    const int inf = INT_MAX;
 
    // Adjacency Matrix for the first
    // graph in the examples
    vector<vector<int> > graph1 = {
        { 0, inf, 9, inf, inf, inf, 3, inf },
        { inf, 0, inf, 10, 1, 8, inf, inf },
        { 9, inf, 0, inf, inf, inf, 11, inf },
        { inf, 10, inf, 0, 5, 13, inf, inf },
        { inf, 1, inf, 5, 0, 3, inf, inf },
        { 8, inf, inf, 13, 3, 0, inf, inf },
        { 3, inf, 11, inf, inf, inf, 0, inf },
        { inf, inf, inf, inf, inf, inf, inf, 0 },
    };
 
    // Find the maximum shortest distances
    vector<int> result1
        = maximumShortesDistances(graph1, N);
 
    // Printing the maximum shortest path
    // distances for each components
    for (int mx1 : result1)
        cout << mx1 << ' ';
 
    return 0;
}

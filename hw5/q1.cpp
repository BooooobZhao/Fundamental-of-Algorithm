// Xuebao Zhao
// 002108354
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#define maxints 50
using namespace std;

int ver[maxints] = { 0 }; // Record all the vertices including the buildings and road intersections

void DIJKSTRA(int C[maxints][maxints], int n)
// C is the graph using adjacency‐matrix
{
    int* D = new int[n]; // The distance value from the starting point to each vertex
    int* P = new int[n]; // An array of predecessor vertices. That is, P[i] is among all the vertices traversed by the shortest path from "start" to "vertex i"
    int* S = new int[n]; // Whether the vertice has been visited, store 1 if it has been visited, and 0 if it has not been visited
    int i, j, k, vl, pre;
    int min, inf = 10000;
    int start, end; //Start building and destination building
    // Input from the users
    cout << "Please input the number of start building：";
    cin >> start;
    cout << "Please input the number of destination building：";
    cin >> end;
    // Find the indexs of start building
    for (int i = 0; i < n; i++) {
        if (start == ver[i]) {
            start = i;
            break; // Jump out of the loop
        }
    }
    // Find the indexs of destination building
    for (int i = 0; i < n; i++) {
        if (end == ver[i]) {
            end = i;
            break; // Jump out of the loop
        }
    }
    vl = start;
    // If there cant find the index successfully, print information and end
    if (start < 0 && start >= n && end < 0 && end >= n)
        cout << "Illegal input";
    else
    {
        // Initialization
        for (i = 0; i < n; i++)
        {
            D[i] = C[vl][i];
            if (D[i] != 10000) // There is a path between i and start
                P[i] = start;
            else
                P[i] = -1;
        }
        for (i = 0; i < n; i++)
            S[i] = 0;
        // Initialize "vertex start" itself
        S[vl] = 1;
        D[vl] = 0;
        // Calendar n - 1 times to find the shortest path of a vertex each time
        for (i = 0; i < n - 1; i++)
        {
            min = inf;
            // Find the current smallest path
            // Among the vertices for which the shortest path is not obtained, find the vertex k closest to start
            for (j = 0; j < n; j++)
                if ((!S[j]) && (D[j] < min)) // Find a shorter vertice
                {
                    // Update most shortest path and vertice
                    min = D[j];
                    k = j;
                }
            S[k] = 1; // Mark vertex k as having obtained the shortest path
            // Correct the current shortest path and predecessor vertices
            for (j = 0; j < n; j++)
                if ((!S[j]) && (D[j] > D[k] + C[k][j]))
                {
                    D[j] = D[k] + C[k][j];
                    P[j] = k;
                }
        }
        // Print the result of dijkstra's shortest path
        cout << endl << "The shortest distance between two buildings: " << D[end] << endl;
        cout << "The shortest path between the two buildings is:" << endl;
        cout << ver[end];
        pre = P[end];
        while (pre != -1) // Until there are no predecessor vertices
        {
            cout << "<--" << ver[pre];
            pre = P[pre]; // Move forward
        }
        cout << endl;
    }
    // Release the memory
    delete[] D;
    delete[] P;
    delete[] S;    
}
int main()
{
    ifstream inf; // File operation
    int count1 = 0;
    int count2 = 16;
    int x, i, j; // Auxiliary variable
    int v1, v2; // The index of the vertices
    int edges[maxints][maxints]; // Store all edges, such as edge[i][j] represents distance from i to j
    int n;  // The number of vertices
    // Initialize so that all vertices are disconnected
    for (int i = 0; i < maxints; i++)
        for (int j = 0; j < maxints; j++)
            edges[i][j] = 10000;
    inf.open("Graph Data.txt"); // Open the file
    if (inf.fail()) // Reports an error if it is not successfully opened
    {
        cerr << "Error: Could not open input file\n";
        exit(1);
    }
    inf.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // Read vertex count
    inf >> x;
    n = x;

    // Until the end of file
    while (true)
    {
        // Read the next integer
        try { inf >> x; }
        catch (std::ifstream::failure e){
            break;
        }
        // Bulidings
        if (x >= 20) {
            for (i = 0; i < count1; i++)
                if (x == ver[i]) // If this vertice is already been recorded, jump out
                    break;
            if (i == count1) // If it is a new vertice, then record it
                ver[count1++] = x;
            v1 = i; // Record index
        }
        // Intersections
        else {
            for (j = 16; j < count2; j++)
                if (x == ver[j]) // If this vertice is already been recorded, jump out
                    break;
            if (j == count2) // If it is a new vertice, then record it
                ver[count2++] = x;
            v1 = j; // Record index
        }
        // Read the next integer
        try { inf >> x; }
        catch (std::ifstream::failure e){
            break;
        }
        // Bulidings
        if (x >= 20) {
            for (i = 0; i < count1; i++)
                if (x == ver[i]) // If this vertice is already been recorded, jump out
                    break;
            if (i == count1) // If it is a new vertice, then record it
                ver[count1++] = x;
            v2 = i; // Record index
        }
        // Intersections
        else {
            for (j = 16; j < count2; j++)
                if (x == ver[j]) // If this vertice is already been recorded, jump out
                    break;
            if (j == count2) // If it is a new vertice, then record it
                ver[count2++] = x;
            v2 = j; // Record index
        }
        // Read the next integer
        try { inf >> x; }
        catch (std::ifstream::failure e){
            break;
        }
        // Record the distance
        edges[v1][v2] = x;
        edges[v2][v1] = x;
    }
    
    DIJKSTRA(edges, n);
    inf.close(); // Close the file at the end of program
    return 0;
}
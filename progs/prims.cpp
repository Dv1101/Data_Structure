#include<iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

// Number of vertices in the graph  
const int V=6;

// Function to find the vertex with minimum key value 
int min_Key(int key[], bool visited[])  
{ 
    int min = 999, min_index;  // 999 represents an Infinite value

    for (int v = 0; v < V; v++) { 
        if (visited[v] == false && key[v] < min) { 
        	// vertex should not be visited
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

// Function to print the final MST stored in parent[]  
int print_MST(int parent[], int cost[V][V])  
{  
    int minCost=0;
	cout<<"Edge \tWeight\n";  
    for (int i = 1; i< V; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";  
		minCost+=cost[i][parent[i]];
    }
	cout<<"Total cost is"<<minCost;
    return 1;
}

   
// Function to find the MST using adjacency cost matrix representation  
void find_MST(int cost[V][V])  
{  
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays 
    for (int i = 0; i< V; i++) { 
        key[i] = 999;    // 99 represents an Infinite value
        visited[i] = false;
        parent[i]=-1;
    }    

    key[0] = 0;  // Include first vertex in MST by setting its key vaue to 0.  
    parent[0] = -1; // First node is always root of MST  

    // The MST will have maximum V-1 vertices  
    for (int x = 0; x < V - 1; x++) 
    {  
        // Finding the minimum key vertex from the 
        //set of vertices not yet included in MST  
        int u = min_Key(key, visited);  

        visited[u] = true;  // Add the minimum key vertex to the MST  

        // Update key and parent arrays
        for (int v = 0; v < V; v++)  
        {
            // cost[u][v] is non zero only for adjacent vertices of u  
            // visited[v] is false for vertices not yet included in MST  
            // key[] gets updated only if cost[u][v] is smaller than key[v]  
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {  
                parent[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    }

    // print the final MST  
	print_MST(parent, cost);  
}  

// main function
int main()  
{  
    int cost[V][V];
	cout<<"Enter the vertices for a graph with 6 vetices"<<endl;
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cin>>cost[i][j];
        }
    }
	
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    find_MST(cost);  

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
  
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;  
}  

/* Data to enter  
 Enter number of vertices and edges:-  
 0 4 0 0 0 2
 4 0 6 0 0 3
 0 6 0 3 0 1
 0 0 3 0 2 0
 0 0 0 2 0 4
 2 3 1 0 4 0

 ans will be-
 Edge   Weight
 5-1     3
 5-2     1
 2-3     3
 3-4     2
 0-5     2
  */
/*  GRAPH:-
               {6}          {3}
          b-------------c----------d
         .|            .           |
     {4}. |           .            |
       .  |          .             |
      .   |{3}     .  {1}          |{2}
     a    |      .                 |
      .   |    .                   |
   {2} .  |  .                     |
        . |.                       |
          f----------------------- e                       
                     {4}

*/
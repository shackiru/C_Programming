#include<stdio.h>


bool allVisited(bool * visited, int n)
{
  for(int i = 0; i < n; i++)
  {
    if(visited[i] == false)
    {
      return false;
    }
  }
  return true;
}

int main(){
	
	int V = 5;
  	int graph[V][V] = 
  { 
	{ 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 }
	}; 

  bool visited[V] = {};
  bool pathVisited[V][V] = {};
	
//	int V = 9;
//	int graph[V][V] = {
//		{0,  4, 0,  0,  0,  0, 0,  8, 0},
//		{4,  0, 8,  0,  0,  0, 0, 11, 0},
//		{0,  8, 0,  7,  0,  4, 0,  0, 2},
//		{0,  0, 7,  0,  9, 14, 0,  0, 0},
//		{0,  0, 0,  9,  0, 10, 0,  0, 0},
//		{0,  0, 4, 14, 10,  0, 2,  0, 0},
//		{0,  0, 0,  0,  0,  2, 0,  1, 6},
//		{8, 11, 0,  0,  0,  0, 1,  0, 7},
//		{0,  0, 2,  0,  0,  0, 6,  7, 0},
//	};


  visited[0] = true;
  int total = 0;

  while(!allVisited(visited, V))
  {
    int src = -1;
    int dst = -1;
    int minimumWeight = 99999;

    for(int i = 0; i < V; i++)
    {
      if(visited[i] == false)
      {
        continue;
      }
      for(int j = 0; j < V; j++)
      {
        if(i == j || visited[j]|| graph[i][j] == 0 || pathVisited[i][j])
        {
          continue;
        }
        if(graph[i][j] < minimumWeight)
        {
          minimumWeight = graph[i][j];
          src = i;
          dst = j;
        }
      }
    }
    if(src != -1 && dst != -1)
    {
      visited[dst] = true;
      pathVisited[src][dst] = true;
      pathVisited[dst][src] = true;
      total += graph[src][dst];
      printf("%d -- %d (%d)\n", src, dst, graph[src][dst]);
    }
  }

  printf("Total: %d\n", total);
	
	return 0;
}

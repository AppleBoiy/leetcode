#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int** adjList = (int**)calloc(numCourses, sizeof(int*));
    int* adjListSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adjList[i] = (int*)malloc(numCourses * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];
        
        adjList[prerequisite][adjListSize[prerequisite]++] = course;
        inDegree[course]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < adjListSize[node]; i++) {
            int neighbor = adjList[node][i];
            if (--inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // Clean up
    for (int i = 0; i < numCourses; i++) {
        free(adjList[i]);
    }
    free(adjList);
    free(adjListSize);
    free(inDegree);
    free(queue);

    return count == numCourses;
}
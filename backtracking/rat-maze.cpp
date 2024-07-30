#include <iostream>
#include <vector>
using namespace std;

void mazeSolver(vector<vector<bool>> &maze, vector<int> &origin, vector<int> &destination, vector<vector<bool>> &visited, string output)
{
    cout << origin[0] << " | " << origin[1] << endl;
    if (origin[0] == destination[0] && origin[1] == destination[1])
    {
        cout << "Reached Destination " << endl;
    }
    if (maze[origin[0]][origin[1]] == 0)
        return;

    //* right
    if (origin[1] < 3 && visited[origin[0]][origin[1] + 1] == false)
    {
        origin[1]++;
        mazeSolver(maze, origin, destination, visited, output);
        visited[origin[0]][origin[1]] = false;

        origin[1]--;
    }
    //* left
    if (origin[1] > 0 && visited[origin[0]][origin[1] - 1] == false)
    {
        origin[1]--;
        mazeSolver(maze, origin, destination, visited, output);
        visited[origin[0]][origin[1]] = false;

        origin[1]++;
    }

    //* top
    if (origin[0] > 0 && visited[origin[0] - 1][origin[1]] == false)
    {
        origin[0]--;
        mazeSolver(maze, origin, destination, visited, output);
        visited[origin[0]][origin[1]] = false;

        origin[0]++;
    }
    //* down
    if (origin[0] < 3 && visited[origin[0] + 1][origin[1]] == false)
    {
        origin[0]++;
        mazeSolver(maze, origin, destination, visited, output);
        visited[origin[0]][origin[1]] = false;
        origin[1]--;
    }
}

int main()
{
    vector<vector<bool>> maze{
        vector<bool>{true, false, false, false},
        vector<bool>{true, true, false, false},
        vector<bool>{true, true, true, false},
        vector<bool>{true, true, true, true},
    };

    vector<vector<bool>> visited(4, vector<bool>(4, false));

    vector<int> origin{0, 0};
    vector<int> destination{3, 3};
    string output = "";
    mazeSolver(maze, origin, destination, visited, output);
}
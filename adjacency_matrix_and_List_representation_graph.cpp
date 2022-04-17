#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

class Graph
{
    public:
    void adjacency_matrix(int edges, vector<vector<int> > &vec);
    void adjacency_diaplay(int vertex, vector<vector<int> > &vec);
    void adjacency_list(int edges, vector<int> *vec);
    void adjacency_list_diaplay(int vertex, vector<int> *vec);
};

void Graph::adjacency_matrix(int edges, vector<vector<int> > &vec)
{
    for (int i = 1; i<=edges; i++)
    {
        int x, y;
        cout << "Enter X and Y where edge is present: ";
        cin >> x >> y;
        vec[x][y] = 1;
        vec[y][x] = 1;

    }
}

void Graph::adjacency_diaplay(int vertex, vector<vector<int> > &vec)
{
    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
        {
            cout << vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::adjacency_list(int edges, vector<int> *vec)
{
    for (int i = 1; i <= edges; i++)
    {
        int x, y;
        cout << "Enter X and Y where edge is present: ";
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
}

void Graph::adjacency_list_diaplay(int vertex, vector<int> *vec)
{
    vector<int>::iterator it;
    for (int i = 1; i <= vertex; i++)
    {
        cout << i << "->";
        for ( it = vec[i].begin(); it != vec[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
int main()
{
    int e, v;
    char yes_no = 'y';
    do
    {
        /* code */
        cout << "Total No. of edges and vertices(Nodes) in graph: ";
        cin >> e >> v;
        vector<vector<int> > adj(v+1, vector<int>(v+1, 0));
        vector<int> adj_list[v+1];
        Graph graph1;
        int select;
        
        cout << "---------------------------Menu---------------------------" << endl << "1. Enter 1 for adjacency matrix" << endl << "2. Enter 2 for adjacency list" << endl << "3. Exit: ";
        cin >> select;
        switch (select)
        {
        case 1:
            /* code */
            cout << endl << "==========================Adjacency Matrix=========================" << endl << endl;
            graph1.adjacency_matrix(e, adj);
            cout << "Adjacency Matrix is : " << endl;
            graph1.adjacency_diaplay(v, adj);
            cout << endl;
            break;
        case 2:
            cout << endl << "===========================Adjacency list=========================="<<endl<<endl;
            graph1.adjacency_list(e, adj_list);
            cout << "Adjacency List is : " << endl;
            graph1.adjacency_list_diaplay(v, adj_list);
            break;
        case 3:
            yes_no = 'n'; 
            break;
        default:
            cout << "You entered wrond input please try again"<<endl;
            break;
        }

    
    } while (yes_no == 'y' or yes_no == 'Y');
     


    return 0;
}
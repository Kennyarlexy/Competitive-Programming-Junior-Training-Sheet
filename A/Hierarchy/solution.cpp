#include <bits/stdc++.h>

using namespace std;

/*
sample test case:
4 2
1 3
2 3 4
*/

int Students, 
    Successful_Students, 
    Wishes, 
    a;

vector<int> Adj[100001];
bool Visited[100001];
//Parent of current current student
int BossOf[100001];
vector<int> Initial_Result(1);

void Topological_Sort(int Student) {
    /*
    traverse through the tree (graph), function is called for every student that is not visited.
    the deepest node of the tree will be added to Initial_Result first. in other words, children entered first then their parent
    */
	Visited[Student] = true;
	for (int i = 0; i < Adj[Student].size(); i++) {
		int child = Adj[Student][i];
		if (!Visited[child])
			Topological_Sort(child);
	}
	Initial_Result.push_back(Student);
}

int main() {

    cin >> Students >> Successful_Students;
	// Adj.resize(Students + 1);

	for (int i = 1; i <= Successful_Students; i++) {
        cin >> Wishes;
		for (int j = 0; j < Wishes; j++) {
            cin >> a;
			Adj[i].push_back(a);
		}
	}

	for (int i = 1; i <= Students; i++) {
		if (!Visited[i])
			Topological_Sort(i);
	}

	int boss = 0;
	for (int i = Students; i > 0; i--) {
        //content of Initial_Result, iterate from right
        // |0| 3 1 4 2
		int Student = Initial_Result[i];
        //Boss of student
		BossOf[Student] = boss;
		boss = Student;
	}

	for (int student = 1; student <= Students; student++) {
        cout << BossOf[student] << "\n";
	}

	return 0;
}

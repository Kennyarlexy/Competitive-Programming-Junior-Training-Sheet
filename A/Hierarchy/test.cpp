#include <bits/stdc++.h>

using namespace std;

int Students, Successful_Students, Wishes, Position, a;
vector<vector<int> > Adj;
bool Visited[100074];
vector<int> Initial_Result;
int Parent[100074];

void Topological_Sort(int Student) {
	Visited[Student] = true;
	for (int i = 0; i < (int) Adj[Student].size(); i++) {
		int child = Adj[Student][i];
		if (!Visited[child])
			Topological_Sort(child);
	}
	Initial_Result.push_back(Student);
}

int main() {
	scanf("%d%d", &Students, &Successful_Students);

	Adj.resize(Students + 1);

	for (int i = 1; i <= Successful_Students; i++) {
		scanf("%d", &Wishes);
		for (int j = 0; j < Wishes; j++) {
			scanf("%d", &a);
			Adj[i].push_back(a);
		}
	}

	for (int i = 1; i <= Students; i++) {
		if (!Visited[i])
			Topological_Sort(i);
	}

	Position = 0;
	for (int i = Students - 1; i >= 0; i--) {
		int Student = Initial_Result[i];
		Parent[Student] = Position;
		Position = Student;
	}

	for (int i = 1; i <= Students; i++) {
		printf("%d\n", Parent[i]);
	}

	return 0;
}

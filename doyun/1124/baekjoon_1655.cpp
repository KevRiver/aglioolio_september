#include <iostream>
#include <queue>

using namespace std;

// ���� 1655 - ����� ���ؿ�
// priority queue
// ��� 2
// 1�ð� ��

// �ִ� �� 1��, �ּ� �� 1��
// �� �� ���̿��� �߰� �� ���� ������ �Դٰ���


struct node
{
	int val;
};

struct node2
{
	int val;
};

// �ּ� ��
bool operator<(node n1, node n2)
{
	if (n1.val > n2.val) return true;
	return false;
}

// �ִ� ��
bool operator<(node2 n1, node2 n2)
{
	if (n1.val < n2.val) return true;
	return false;
}

priority_queue<node> pq_min;
priority_queue<node2> pq_max;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, tmp;
	cin >> n >> a;
	pq_max.push({ a });
	cout << a << '\n';

	for (int i = 1; i < n; i++)
	{
		cin >> a;

		// push
		if (pq_max.empty()) pq_min.push({ a });
		else if(pq_min.empty()) pq_max.push({ a });
		else
		{
			if (pq_max.top().val > a) pq_max.push({ a });
			else pq_min.push({ a });
		}

		// �߰� ã�� (�� �� ���� ������ ������)
		while (pq_min.size() != pq_max.size() && pq_min.size() + 1 != pq_max.size())
		{
			if (pq_max.size() > pq_min.size() + 1)
			{
				tmp = pq_max.top().val;
				pq_max.pop();
				pq_min.push({ tmp });
			}
			else
			{
				tmp = pq_min.top().val;
				pq_min.pop();
				pq_max.push({ tmp });
			}
		}

		cout << pq_max.top().val << '\n';
		
	}

	return 0;

}
#include <iostream>
#include <queue>

#define MAX_MANAGER_SIZE 9
#define MAX_CUSTOMER_SIZE 1000
using namespace std;

struct Customer
{
	int idx;
	bool is_end;
	int arrive_num;
	int reception_desk;
	int repair_desk;
};

struct Manager
{
	bool is_busy;
	int ability_time;
	int remain_time;
	int customer_idx;
};

Manager reception_man_list[MAX_MANAGER_SIZE];
Manager repair_man_list[MAX_MANAGER_SIZE];
Customer customer_list[MAX_CUSTOMER_SIZE];

queue<Customer*> reception_ready_q; // 접수 창구 손님 대기 큐
queue<Customer*> repair_ready_q; // 정비 창구 손님 대기 큐

int N, M; // 접수 창구, 정비 창구
int K; // 고객의 수
int A, B; // 지갑 두고간 손님이 방문한  접수, 정비 창구번호

void init_manager() {
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;

		reception_man_list[i].ability_time = time;
		reception_man_list[i].is_busy = false;
		reception_man_list[i].remain_time = -1;
		reception_man_list[i].customer_idx = -1;
	}

	for (int j = 0; j < M; j++) {
		int time;
		cin >> time;

		repair_man_list[j].ability_time = time;
		repair_man_list[j].is_busy = false;
		repair_man_list[j].remain_time = -1;
		repair_man_list[j].customer_idx = -1;
	}
}

void init_customer() {
	for (int i = 0; i < K; i++) {
		int time;
		cin >> time;

		customer_list[i].idx = i;
		customer_list[i].is_end = false;
		customer_list[i].arrive_num = time;
		customer_list[i].reception_desk = -1;
		customer_list[i].repair_desk = -1;
	}
}

bool check_all_customer_end() {
	for (int i = 0; i < K; i++) {
		if (!customer_list[i].is_end) {
			return false;
		}
	}
	return true;
}

void next_time(int t) {
	// 도착한 손님을 접수 창구 고객 큐에 넣는다.
	for (int i = 0; i < K; i++) {
		if (customer_list[i].arrive_num == t) {
			reception_ready_q.push(&customer_list[i]);
		}
	}

	// 접수 창구 1초 경과 처리 && 빈자리에 손님을 할당한다
	bool is_exist_reception_customer = !reception_ready_q.empty();
	for (int i = 0; i < N; i++) {
		Manager *reception_man = &reception_man_list[i];
		if (reception_man->is_busy) {
			if (reception_man->remain_time == 0) {
				int customer_idx = reception_man->customer_idx;
				Customer *customer = &customer_list[customer_idx];
				repair_ready_q.push(customer);
				reception_man->is_busy = false;
				reception_man->remain_time = reception_man->ability_time;
				reception_man->customer_idx = -1;
			}
			else {
				reception_man->remain_time--;
			}
		}
		
		if (!reception_man->is_busy) {
			if (is_exist_reception_customer) {
				Customer *customer = reception_ready_q.front();
				customer->reception_desk = i + 1;
				reception_man->is_busy = true;
				reception_man->customer_idx = customer->idx;
				reception_man->remain_time = reception_man->ability_time;
				reception_man->remain_time--;
				reception_ready_q.pop();
				is_exist_reception_customer = !reception_ready_q.empty();
			}
		}
	}

	// 정비 창구 1초 경과 처리 && 빈자리에 손님을 할당한다
	bool is_exist_repair_customer = !repair_ready_q.empty();
	for (int j = 0; j < M; j++) {
		Manager *repair_man = &repair_man_list[j];
		if (repair_man->is_busy) {
			if (repair_man->remain_time == 0) {
				int customer_idx = repair_man->customer_idx;
				Customer *customer = &customer_list[customer_idx];
				customer->is_end = true;
				repair_man->is_busy = false;
				repair_man->remain_time = repair_man->ability_time;
				repair_man->customer_idx = -1;
			}
			else {
				repair_man->remain_time--;
			}
		}
		
		if (!repair_man->is_busy) {
			if (is_exist_repair_customer) {
				Customer *customer = repair_ready_q.front();
				customer->repair_desk = j + 1;
				repair_man->is_busy = true;
				repair_man->customer_idx = customer->idx;
				repair_man->remain_time = repair_man->ability_time;
				repair_man->remain_time--;
				repair_ready_q.pop();
				is_exist_repair_customer = !repair_ready_q.empty();
			}

		}
	}
}

int find_customer(int reception_desk, int repair_desk) {
	int sum = 0;

	for (int i = 0; i < K; i++) {
		if (customer_list[i].reception_desk == reception_desk) {
			if (customer_list[i].repair_desk == repair_desk) {
				sum += (i + 1);
			}
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		cin >> N >> M >> K >> A >> B;

		init_manager();
		init_customer();
		
		int t = 0;
		while (!check_all_customer_end()) {
			next_time(t);
			t++;
		}

		int ans = find_customer(A, B);

		if (ans == 0) {
			cout << '#' << k << ' ' << -1 << '\n';
		}
		else {
			cout << '#' << k << ' ' << ans << '\n';
		}
	}

	return 0;
}
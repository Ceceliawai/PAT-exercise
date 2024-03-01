#include <algorithm>
#include <iostream>
using namespace std;
int origin[110], input[110];  // ԭʼ���ݣ������˺������
int N;
/**
 * @brief ��pre+1��index֮�������key
 *
 * @param key Ҫ�����Ԫ��
 * @param index Ҫ����Ԫ����ԭʼ�����е�λ��
 * @param pre �����п�ʼλ�õ�ǰһ��������ʵ��merge sort��
 * @return ** void
 */
void insert(int key, int index, int pre) {
    if (index == 1) {
        input[index] = key;
        return;
    }
    input[0] = input[index];
    int j;
    for (j = index - 1; j > pre; j--) {
        if (input[0] < input[j])
            input[j + 1] = input[j];
        else
            break;
    }
    j = max(pre + 1, j + 1);
    input[j] = input[0];
    return;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> origin[i];
    for (int i = 1; i <= N; i++) cin >> input[i];
    int pre, cur;
    pre = 1;
    cur = 1;
    bool flag = true;  // true����insert
    for (int i = 2; i <= N; i++) {
        if (origin[i] != input[i]) {
            // ��ǰ�ж�
            // ����б䶯����������ȫ������˵������insert
            cur = i;
            int val = input[cur];
            for (int j = cur - 1; j >= pre - 1 && j >= 1; j--) {
                if (input[j] > val) {
                    flag = false;
                    break;
                } else
                    val = input[j];
            }
            pre = cur;
            if (flag == false) break;
        }
    }
    if (flag == true) {
        // insert
        cout << "Insertion Sort" << endl;
        // �ҵ���һ��δ�������
        int i;
        for (i = 2; i <= N; i++) {
            if (input[i] < input[i - 1]) break;
        }
        // �ٲ���һ����
        insert(input[i], i, 0);
        for (int i = 1; i <= N; i++) {
            if (i != 1) cout << " ";
            cout << input[i];
        }
    } else {
        // merge
        cout << "Merge Sort" << endl;
        int d = 1;
        int mind = N + 1;
        // �ҵ���ǰ�����г��ȣ���������������̵��Ǹ�
        for (int i = 2; i <= N; i++) {
            if (input[i] > input[i - 1])
                d++;
            else {
                mind = min(d, mind);
                d = 1;
            }
        }
        int pre = 0;  // ��һ�������λ��
        int i;
        for (i = 1; i <= N; i = i + mind * 2) {
            pre = i - 1;
            // i��i+mind-1���Ѿ��ź��������1
            // i+mind��i+mind*2-1���Ѿ��ź��������2
            // ��i+mind��i+mind*2-1�������β�������
            // ����ʹ��i��i+mind*2-1�������
            // ��һ����ʼλ�ã�i+mind*2
            for (int j = i + mind; j < i + mind * 2 && j <= N; j++) {
                insert(input[j], j, pre);
            }
        }
        int j = i;
        while (j <= N) {
            insert(input[j], j, i - 1);
        }
        for (int i = 1; i <= N; i++) {
            if (i != 1) cout << " ";
            cout << input[i];
        }
    }
    return 0;
}

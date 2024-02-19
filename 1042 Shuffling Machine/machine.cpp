#include <iostream>
#include <string>

using namespace std;
int ranktoindex[55];
int indextorank[55];
int K;

// 这有点太蠢了，但我真的想不出更好的办法哈哈。。。
string cards[55] = {
    "",    "S1",  "S2",  "S3",  "S4",  "S5",  "S6",  "S7",  "S8",  "S9", "S10",
    "S11", "S12", "S13", "H1",  "H2",  "H3",  "H4",  "H5",  "H6",  "H7", "H8",
    "H9",  "H10", "H11", "H12", "H13", "C1",  "C2",  "C3",  "C4",  "C5", "C6",
    "C7",  "C8",  "C9",  "C10", "C11", "C12", "C13", "D1",  "D2",  "D3", "D4",
    "D5",  "D6",  "D7",  "D8",  "D9",  "D10", "D11", "D12", "D13", "J1", "J2"};

int main() {
    cin >> K;
    for (int i = 1; i < 55; i++) {
        int rank;
        cin >> rank;
        ranktoindex[rank] = i;
        indextorank[i] = rank;
    }

    for (int i = 1; i < 55; i++) {
        int index;
        int rank;
        rank = i;
        for (int j = 0; j < K; j++) {
            index = ranktoindex[rank];
            rank = index;
        }
        index = rank;
        if (i != 1) cout << " ";
        cout << cards[index];
    }
    return 0;
}
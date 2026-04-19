#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define BIT_VECTOR_LENGTH 4

// 1. 유효성 검사: 4자리인지, 0과 1로만 구성되었는지 확인
int check_validity(char *input) {
    if (strlen(input) != BIT_VECTOR_LENGTH) return 0;
    for (int i = 0; i < BIT_VECTOR_LENGTH; i++) {
        if (input[i] != '0' && input[i] != '1') return 0;
    }
    return 1;
}

// 2. 문자열 입력을 배열로 변환 ('0' -> 0, '1' -> 1)
void init_bit_vector(char *input, char *bv) {
    for (int i = 0; i < BIT_VECTOR_LENGTH; i++) {
        bv[i] = input[i] - '0';
    }
}

// 3. 비트 벡터 출력
void print_bit_vector(char *bv) {
    for (int i = 0; i < BIT_VECTOR_LENGTH; i++) {
        cout << (int)bv[i];
    }
}

// --- Representation 함수들 ---

// Unsigned (B2U)
unsigned int b2u(char *bv) {
    unsigned int sum = 0;
    for (int i = 0; i < BIT_VECTOR_LENGTH; i++) {
        // MSB가 index 0, LSB가 index 3인 경우: 2^(3-i)
        if (bv[i]) sum += pow(2, BIT_VECTOR_LENGTH - 1 - i);
    }
    return sum;
}

// Sign-Magnitude (B2S)
int b2s(char *bv) {
    int sign = (bv[0] == 1) ? -1 : 1;
    int magnitude = 0;
    for (int i = 1; i < BIT_VECTOR_LENGTH; i++) {
        if (bv[i]) magnitude += pow(2, BIT_VECTOR_LENGTH - 1 - i);
    }
    return sign * magnitude;
}

// Ones' Complement (B2O)
int b2o(char *bv) {
    if (bv[0] == 0) return b2u(bv);
    // 음수인 경우: 모든 비트 반전 후 b2u 결과에 마이너스
    return -(pow(2, BIT_VECTOR_LENGTH - 1) - 1 - (b2u(bv) & 0x7)); // 단순화된 로직
}

// Two's Complement (B2T)
int b2t(char *bv) {
    int val = 0;
    for (int i = 0; i < BIT_VECTOR_LENGTH; i++) {
        int weight = pow(2, BIT_VECTOR_LENGTH - 1 - i);
        if (i == 0) val -= bv[i] * weight; // MSB는 음의 가중치
        else val += bv[i] * weight;
    }
    return val;
}

// --- Addition 함수들 ---

// 전가산기(Full Adder) 로직을 이용한 비트 덧셈
void bit_addition(char *bv1, char *bv2, char *result) {
    int carry = 0;
    // LSB(오른쪽)부터 MSB(왼쪽) 방향으로 계산
    for (int i = BIT_VECTOR_LENGTH - 1; i >= 0; i--) {
        int sum = bv1[i] + bv2[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
}

unsigned int unsigned_addition(char *bv1, char *bv2) {
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2u(result);
}

int twos_complement_addition(char *bv1, char *bv2) {
    char result[BIT_VECTOR_LENGTH];
    bit_addition(bv1, bv2, result);
    return b2t(result);
}

// 메인 함수
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: ./bit_vector [bv1] [bv2]" << endl;
        return 1;
    }

    if (!check_validity(argv[1]) || !check_validity(argv[2])) {
        cout << "Invalid input! Must be 4-bit binary strings." << endl;
        return 1;
    }

    char bv1[BIT_VECTOR_LENGTH], bv2[BIT_VECTOR_LENGTH];
    init_bit_vector(argv[1], bv1);
    init_bit_vector(argv[2], bv2);

    cout << "BV1: "; print_bit_vector(bv1); cout << " (B2U: " << b2u(bv1) << ", B2T: " << b2t(bv1) << ")" << endl;
    cout << "BV2: "; print_bit_vector(bv2); cout << " (B2U: " << b2u(bv2) << ", B2T: " << b2t(bv2) << ")" << endl;

    cout << "\n--- Addition Results ---" << endl;
    cout << "Unsigned Addition Result: " << unsigned_addition(bv1, bv2) << endl;
    cout << "Two's Complement Addition Result: " << twos_complement_addition(bv1, bv2) << endl;

    return 0;
}
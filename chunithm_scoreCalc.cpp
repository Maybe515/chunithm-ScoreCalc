#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SCORE 1010000
#define RED_J_DEFAULT_RATIO 0.25

// 入力補助関数
int inputInt(const char *msg, int min, int max) {
    int val;
    while (1) {
        printf("%s", msg);
        if (scanf("%d", &val) == 1 && val >= min && val <= max) {
            return val;
        }
        printf("無効な入力です。もう一度入力してください。\n\n");
        while (getchar() != '\n'); // バッファクリア
    }
}

// 赤J割合の計算
double inputRedJRatio(void) {
    char ans;
    int totalRedJ = 0, totalNotes = 0;

    while (1) {
        printf("実際の【JUSTICE】の割合を算出しますか？【Y/N/?】:");
        scanf(" %c", &ans);   // 先頭の空白で改行や空白をスキップ
        ans = (char)toupper((unsigned char)ans);

        if (ans == 'Y') {
            for (int i = 1; i <= 10; i++) {
                int redJ = inputInt("%d曲目の赤J数:", 0, 100000);
                int notes = inputInt("そのノーツ数:", 1, 100000);
                totalRedJ += redJ;
                totalNotes += notes;
            }
            if (totalNotes > 0) {
                return (double)totalRedJ / totalNotes;
            } else {
                return RED_J_DEFAULT_RATIO;
            }
        } else if (ans == 'N') {
            return RED_J_DEFAULT_RATIO;
        } else if (ans == '?') {
            printf("10曲分の「合計ノーツ数」から「JUSTICE」が出た割合を算出します。\n※「ATTACK数」「ミス数」は考慮しないでください。\n\n");
        } else {
            printf("無効な入力です。Y/N/? を入力してください。\n\n");
        }
    }
}

int main(void) {
    int retry;
    printf("【チュウニズム スコア計算機】\n指定した「スコア」「合計ノーツ数」「ミス数」から【JUSTICE】と【ATTACK】の数を算出してリザルトを出力します。\n");

    do {
        int score = inputInt("\nスコア:", 0, MAX_SCORE);
        int notes = inputInt("ノーツ数:", 1, 100000);

        // 理論値 or 0 の場合は即出力
        if (score == MAX_SCORE) {
            printf("リザルト:%d-0-0-0\n", notes);
            printf("Finished\n");
            return 0;
        }
        if (score == 0) {
            printf("リザルト:0-0-0-%d\n", notes);
            printf("Finished\n");
            return 0;
        }

        // 赤J割合
        double redJRatio = inputRedJRatio();

        // ミス数
        int miss = inputInt("ミス数:", 0, notes);

        // 計算処理
        int diff = MAX_SCORE - score;
        double missScore = (double)MAX_SCORE / notes;
        diff -= miss * missScore;

        double jsScore = 10000.0 / notes;
        double redJ = floor((diff / jsScore) * redJRatio);
        diff -= redJ * jsScore;

        double atkScore = 510000.0 / notes;
        double atk = floor(diff / atkScore);
        diff -= atk * atkScore;

        if (diff >= jsScore) {
            redJ += floor(diff / jsScore);
        }

        int jc = notes - (int)(redJ + atk + miss);

        // 出力
        printf("\nJUSTICE CRITICAL 1あたりのスコア: %.0f\n", missScore);
        printf("JUSTICE 1あたりのスコア: %.0f\n", jsScore);
        printf("ATTACK 1あたりのスコア: %.0f\n", atkScore);
        printf("リザルト:%d-%.0f-%.0f-%d\n", jc, redJ, atk, miss);

        retry = inputInt("\n再入力する場合は「1」を入力:", 0, 1);
    } while (retry == 1);

    printf("Finished\n");
    return 0;
}

/*
Hiện tại giá điện đang được tính theo bậc thang gồm 6 mức (mức điều chỉnh từ 04/05/2023), với giá thấp nhất (bậc 1) là 1.728VND và giá bậc cao nhất là 3.015 VND. Tuy nhiên EVN đang đề xuất một cách tính giá điện bậc thang mới chỉ gồm 5 mức như hinh dưới, giá thấp nhất (bậc 1) khoảng 1.728 đồng một kWh và cao nhất (bậc 5) là 3.457 đồng một kWh. 

Bậc	Biểu giá hiện hành	Phương án 5 bậc
  	Mức sử dụng	Giá (*)	Mức sử dụng	Giá
1	0-50 kWh	1.728	0-100 kWh	1.728
2	51-100 kWh	1.786	101-200 kWh	2.074
3	101-200 kWh	2.074	201-400 kWh	2.612
4	201-300 kWh	2.612	401-700 kWh	3.111
5	301-400 kWh	2.919	701 kWh trở lên	3.457
6  	401 kWh trở lên	3.015		
(*) Giá chưa bao gồm thuế VAT

Hãy xây dựng chương trình nhập vào số kwh điện của một hộ tiêu thụ và so sánh xem theo bảng giá mới đang lấy ý kiến thì tiền điện tiêu thụ của hộ đó sẽ tăng thêm hay giảm đi bao nhiêu.
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void solve(int kwh) { 
        // Current 6-level pricing
        vector<int> levels6   = {50,   50,   100,  100,  100,  INT_MAX};
        vector<double> price6 = {1728, 1786, 2074, 2612, 2919, 3015};

        // Proposed 5-level pricing
        vector<int> levels5   = {100,  100,  200,  300,  INT_MAX}; 
        vector<double> price5 = {1728, 2074, 2612, 3111, 3457};

        double cost6 = 0, cost5 = 0;
        int rem6 = kwh, rem5 = kwh;

        // Calculate cost for current 6-level
        for (int i = 0; i < 6; i++) {
            int use = min(rem6, levels6[i]);
            cost6 += use * price6[i];
            rem6  -= use;
            if (rem6 <= 0) break;
        }

        // Calculate cost for proposed 5-level
        for (int i = 0; i < 5; i++) {
            int use = min(rem5, levels5[i]);
            cost5 += use * price5[i];
            rem5  -= use;
            if (rem5 <= 0) break;
        }

        // Include VAT 10%
        cost6 *= 1.1;
        cost5 *= 1.1;

        double diff = cost5 - cost6;

        printf("%.2lf", diff);
    }
};

int main() {
    int kwh;
    cin >> kwh;
    Solution solution = Solution();
    solution.solve(kwh);
    return 0;
}

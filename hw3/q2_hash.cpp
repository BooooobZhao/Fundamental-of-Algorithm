// Xuebao Zhao
// 002108354
#include<iostream>
#include<random>

using namespace std;

int main(){
    int months[1000], days[1000], years[1000];// Arrays to store months, days, and years
    int births[1000];// Arrays to store births
    int hash1[97], hash2[98], hash3[100], hash4[101];
    int count = 0;
    int min[4], max[4];
    float mean[4], var[4];

    random_device rd1, rd2, rd3;// Will be used to obtain a seed for the random months, days, and years
	mt19937 gen1(rd1());// Standard mersenne_twister_engine seeded with rd() for months
    mt19937 gen2(rd2());// Standard mersenne_twister_engine seeded with rd() for months
    mt19937 gen3(rd3());// Standard mersenne_twister_engine seeded with rd() for months
	uniform_int_distribution<> distrib1(1, 12);
    uniform_int_distribution<> distrib2(1, 27);
    uniform_int_distribution<> distrib3(0, 4);

	for (int i = 0; i < 1000; i++)
	{
		months[i] = distrib1(gen1);// Fill the array with random values.
        days[i] = distrib2(gen2);
        years[i] = distrib3(gen3);
        births[i] = months[i] * 10000 + days[i] * 100 + years[i];// Store into the births array
        
        // Stroe into 4 hash tables
        hash1[births[i] % 97]++;
        hash2[births[i] % 98]++;
        hash3[births[i] % 100]++;
        hash4[births[i] % 101]++;
	}

    // m = 97
    max[0] = min[0] = hash1[0];
    for(int i = 0; i < 97 ; i++){
        // 0 do not need to - 1
        if(hash1[i] > 1){
            hash1[i]--;
        }
        // Minimum
        min[0] = (min[0] < hash1[i] ? min[0] : hash1[i]);
        // Maximum
        max[0] = (max[0] > hash1[i] ? max[0] : hash1[i]);
        // Sum
        mean[0] += hash1[i];
    }
    // Mean
    mean[0] = mean[0] / 97;
    // Variance
    for(int i = 0; i < 97 ; i++){
        var[0] += (hash1[i] - mean[0]) * (hash1[i] - mean[0]);
    }
    var[0] = var[0] / 97;
    // print
    cout << endl << "---------------- m = 97 -----------------" << endl;
    cout << min[0] << endl;
    cout << max[0] << endl;
    cout << mean[0] << endl;
    cout << var[0] << endl;
    cout << "-----------------------------------------" << endl;
    
    // m = 98
    max[1] = min[1] = hash2[0];
    for(int i = 0; i < 98 ; i++){
        // 0 and 1 do not need to -1
        if(hash2[i] > 1){
            hash2[i]--;
        }
        // Minimum
        min[1] = (min[1] < hash2[i] ? min[1] : hash2[i]);
        // Maximum
        max[1] = (max[1] > hash2[i] ? max[1] : hash2[i]);
        // Sum
        mean[1] += hash2[i];
    }
    // Mean
    mean[1] = mean[1] / 98;
    // Variance
    for(int i = 0; i < 98 ; i++){
        var[1] += (hash2[i] - mean[1]) * (hash2[i] - mean[1]);
    }
    var[1] = var[1] / 98;
    // Print
    cout << endl << "---------------- m = 98 -----------------" << endl; 
    cout << min[1] << endl;
    cout << max[1] << endl;
    cout << mean[1] << endl;
    cout << var[1] << endl;
    cout << "-----------------------------------------" << endl;

    // m = 100
    max[2] = min[2] = hash3[0];
    for(int i = 0; i < 100 ; i++){
        // 0 and 1 do not need to -1
        if(hash3[i] > 1){
            hash3[i]--;
        }
        // Minimum
        min[2] = (min[2] < hash3[i] ? min[2] : hash3[i]);
        // Maximum
        max[2] = (max[2] > hash3[i] ? max[2] : hash3[i]);
        // Sum
        mean[2] += hash3[i];
    }
    // Mean
    mean[2] = mean[2] / 100;
    //Variance
    for(int i = 0; i < 100 ; i++){
        var[2] += (hash3[i] - mean[2]) * (hash3[i] - mean[2]);
    }
    var[2] = var[2] / 100;
    //Print
    cout << endl << "---------------- m = 100 -----------------" << endl; 
    cout << min[2] << endl;
    cout << max[2] << endl;
    cout << mean[2] << endl;
    cout << var[2] << endl;
    cout << "------------------------------------------" << endl;

    // m = 101
    max[3] = min[3] = hash4[0];
    for(int i = 0; i < 101 ; i++){
        // 0 and 1 do not need to -1
        if(hash4[i] > 1){
            hash4[i]--;
        }
        // Minimum
        min[3] = (min[3] < hash4[i] ? min[3] : hash4[i]);
        // Maximum
        max[3] = (max[3] > hash4[i] ? max[3] : hash4[i]);
        // Sum
        mean[3] += hash4[i];
    }
    // Mean
    mean[3] = mean[3] / 101;
    // Variance
    for(int i = 0; i < 101 ; i++){
        var[3] += (hash4[i] - mean[3]) * (hash4[i] - mean[3]);
    }
    var[3] = var[3] / 100;
    //Print
    cout << endl << "---------------- m = 101 -----------------" << endl; 
    cout << min[3] << endl;
    cout << max[3] << endl;
    cout << mean[3] << endl;
    cout << var[3] << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}
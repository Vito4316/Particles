//
// Created by vito on 02/06/2022.
//

#ifndef PARTICLES_TIMEBENCHMARK_H
#define PARTICLES_TIMEBENCHMARK_H
#include <chrono>
#include <iostream>
#include <iomanip>

class timeBenchmark {
    std::chrono::high_resolution_clock::time_point t1;
public:
    timeBenchmark() {
        t1 = std::chrono::high_resolution_clock::now();
    }

    virtual ~timeBenchmark() {
        auto t2= std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(t1).time_since_epoch();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(t2).time_since_epoch();

        auto duration = (end - start).count();
        double ms = duration * 0.0001;

        std::cout << "It took me " <<std::setprecision(30)<< ms << " seconds."<<std::endl;
    }
};


#endif //PARTICLES_TIMEBENCHMARK_H

#ifndef TETHREADJOINER_H
#define TETHREADJOINER_H

#include <thread>
#include <vector>

namespace TE::Threading {
    class ThreadJoiner {
      public:
        ThreadJoiner(std::vector<std::thread> &threads) : m_threads(threads) {}

        ~ThreadJoiner() {
            for (auto &thread : m_threads) {
                if (thread.joinable())
                    thread.join();
            }
        }

      private:
        std::vector<std::thread> &m_threads;
    };
}

#endif

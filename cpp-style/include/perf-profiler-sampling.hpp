#pragma once

#include <map>

#include <profiler.hpp>
#include <perf-event.hpp>
#include <perf-utils.hpp>


class PerfProfilerSampling : public IProfiler
{
    public:
        explicit PerfProfilerSampling(uint32_t samplePeriod = 100000);
        ~PerfProfilerSampling() = default;

        void run(int argc, char **argv) override;

    private:
        struct perf_event_attr pe_;

        long samplesCnt_;

        std::map<uint64_t, double> map_;

        void mapPrint_();

        void runTest_(int argc, char **argv);
        void runMonitor_(const pid_t childPid);

        void pagePrint_(const RecordPage& page);
        void samplePrint_(const RecordSample& sample);
        void sampleCopy_(const RecordSample& sample);
};

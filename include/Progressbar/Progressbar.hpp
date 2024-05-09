#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Bar
{
    class ProgressBar_v1
    {
    public:
        std::string doneSymbol = "#";
        std::string todoSymbol = " ";
        std::string startSymbol = "[";
        std::string endSymbol = "]";
        std::string Output;
        int maxSymbols = 25;
        int n_done = 0;
        std::string EmptyStr;
        int LastSizeStr;
        std::string OutputStr;
        int Percentage;

        void Update(double DownloadedSize = 0.0, double TotalSize = 0.0);
        void ResetAll();

    protected:
        std::string round(double value);

        std::string AutoConvertSize(float Size);

        double convert_to_MB(double Value);

        double convert_to_KB(double Value);

        double convert_to_GB(double Value);
    };

    class ProgressBar_v2
    {
    public:
        int Percentage;
        std::string ProgressSymbols[4] = {"/", "-", "\\", "|"};
        int n = 0;
        void Update();

    protected:
    };
}
#endif
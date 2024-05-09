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
        std::string output;
        int maxSymbols = 25;
        int n_done = 0;
        std::string EmptyStr;
        int lastSizeStr;
        std::string outputStr;
        int Progress;

        void Update(double DownloadedSize = 0.0, double TotalSize = 0.0);
        void ResetAll();
        void setMaxSymbols(int max);
        void setProgress(int Progress);
        void setDoneSymbol(std::string symbol);
        void setTodoSymbol(std::string symbol);
        void setStartSymbol(std::string symbol);
        void setEndSymbol(std::string symbol);

    protected:
        std::string round(double value);

        std::string autoConvertSize(float Size);

        double convert_to_MB(double Value);

        double convert_to_KB(double Value);

        double convert_to_GB(double Value);
    };

    class ProgressBar_v2
    {
    public:
        int Progress;
        std::string ProgressSymbols[4] = {"/", "-", "\\", "|"};
        int n = 0;
        void Update();

    protected:
    };
}
#endif
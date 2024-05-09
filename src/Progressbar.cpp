#include <Progressbar/Progressbar.hpp>

void Bar::ProgressBar_v1::update(double DownloadedSize, double TotalSize)
{
    if (progress < 100)
        progress += 1;
    output = startSymbol;
    for (int i = 0; i < n_done; i++)
    {
        output += doneSymbol;
    }
    if (progress <= 100)
    {
        if (progress % 4 == 0)
        {
            output += doneSymbol;
            n_done += 1;
        }
    }
    if (maxSymbols - n_done)
    {
        for (int i = 0; i < (maxSymbols - n_done); i++)
        {
            output += todoSymbol;
        }
    }
    output += endSymbol;
    emptyStr = "";
    for (int i = 0; i < lastSizeStr; i++)
    {
        emptyStr += todoSymbol;
    }
    std::cout << "\r" << emptyStr << std::flush;
    outputStr = output + " " + std::to_string(progress) + "%  ";
    if (DownloadedSize != 0.0 && TotalSize != 0.0)
    {
        if (progress == 100)
        {
            outputStr = outputStr + autoConvertSize(TotalSize) + " / " + autoConvertSize(TotalSize);
        }
        else
        {
            outputStr = outputStr + autoConvertSize(DownloadedSize) + " / " + autoConvertSize(TotalSize);
        }
    }
    std::cout << "\r" << outputStr << std::flush;
    lastSizeStr = outputStr.size();
}

void Bar::ProgressBar_v1::resetAll()
{
    std::cout << "" << std::endl;
    progress = 0;
    lastSizeStr = 0;
    outputStr = "";
    emptyStr = "";
    output = "";
    n_done = 0;
}

void Bar::ProgressBar_v1::setMaxSymbols(int max)
{
    maxSymbols = max;
}
void Bar::ProgressBar_v1::setProgress(int Progress)
{
    Progress = Progress;
}
void Bar::ProgressBar_v1::setDoneSymbol(std::string symbol)
{
    doneSymbol = symbol;
}
void Bar::ProgressBar_v1::setTodoSymbol(std::string symbol)
{
    todoSymbol = symbol;
}
void Bar::ProgressBar_v1::setStartSymbol(std::string symbol)
{
    startSymbol = symbol;
}
void Bar::ProgressBar_v1::setEndSymbol(std::string symbol)
{
    endSymbol = symbol;
}

std::string Bar::ProgressBar_v1::round(double value)
{
    // Print value to a string
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    std::string str = ss.str();
    // Ensure that there is a decimal point somewhere (there should be)
    if (str.find('.') != std::string::npos)
    {
        // Remove trailing zeroes
        str = str.substr(0, str.find_last_not_of('0') + 1);
        // If the decimal point is now the last character, remove that as well
        if (str.find('.') == str.size() - 1)
        {
            str = str.substr(0, str.size() - 1);
        }
    }
    return str;
}

std::string Bar::ProgressBar_v1::autoConvertSize(float Size)
{
    std::string ConvertedSize;
    Size = convert_to_KB(Size);
    if (Size >= 1024)
    {
        ConvertedSize = round(convert_to_MB(Size)) + " MB";
    }
    else if (convert_to_MB(Size) >= 1024)
    {
        ConvertedSize = round(convert_to_GB(Size)) + " GB";
    }
    else
    {
        ConvertedSize = round(Size) + " KB";
    }
    return ConvertedSize;
}

double Bar::ProgressBar_v1::convert_to_MB(double Value)
{
    double NewValue = Value / 1024;
    return NewValue;
}

double Bar::ProgressBar_v1::convert_to_KB(double Value)
{
    double NewValue = Value / 1024;
    return NewValue;
}

double Bar::ProgressBar_v1::convert_to_GB(double Value)
{
    double NewValue = Value / 1024;
    return NewValue;
}

void Bar::ProgressBar_v2::update()
{
    std::cout << "\r" << progressSymbols[n] << std::flush;
    if (n == (end(progressSymbols) - begin(progressSymbols) - 1))
        n = 0;
    else
        n++;
}
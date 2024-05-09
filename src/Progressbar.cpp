#include <Progressbar/Progressbar.hpp>

void Bar::ProgressBar_v1::Update(double DownloadedSize, double TotalSize)
{
    Percentage = static_cast<float>(DownloadedSize) / static_cast<float>(TotalSize) * 100;
    // if (Percentage < 100)
    //     Percentage += 1;
    Output = startSymbol;
    for (int i = 0; i < n_done; i++)
    {
        Output += doneSymbol;
    }
    if (Percentage <= 100)
    {
        if (Percentage % 4 == 0)
        {
            Output += doneSymbol;
            n_done += 1;
        }
    }
    if (maxSymbols - n_done)
    {
        for (int i = 0; i < (maxSymbols - n_done); i++)
        {
            Output += todoSymbol;
        }
    }
    Output += endSymbol;
    EmptyStr = "";
    for (int i = 0; i < LastSizeStr; i++)
    {
        EmptyStr += todoSymbol;
    }
    std::cout << "\r" << EmptyStr << std::flush;
    OutputStr = Output + " " + std::to_string(Percentage) + "%  ";
    if (DownloadedSize != 0.0 && TotalSize != 0.0)
    {
        if (Percentage == 100)
        {
            OutputStr = OutputStr + AutoConvertSize(TotalSize) + " / " + AutoConvertSize(TotalSize);
        }
        else
        {
            OutputStr = OutputStr + AutoConvertSize(DownloadedSize) + " / " + AutoConvertSize(TotalSize);
        }
    }
    std::cout << "\r" << OutputStr << std::flush;
    LastSizeStr = OutputStr.size();
}

void Bar::ProgressBar_v1::ResetAll()
{
    std::cout << "" << std::endl;
    Percentage = 0;
    LastSizeStr = 0;
    OutputStr = "";
    EmptyStr = "";
    Output = "";
    n_done = 0;
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

std::string Bar::ProgressBar_v1::AutoConvertSize(float Size)
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

void Bar::ProgressBar_v2::Update()
{
    std::cout << "\r" << ProgressSymbols[n] << std::flush;
    if (n == (end(ProgressSymbols) - begin(ProgressSymbols) - 1))
        n = 0;
    else
        n++;
}
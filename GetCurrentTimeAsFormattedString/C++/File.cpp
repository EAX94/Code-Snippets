std::wstring GetTimeString() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);
    std::wstringstream wss;

    wss << std::put_time(&now_tm, L"%yy-mm-%dd-%Hh-%Mm-%Ss");

    return wss.str();
}
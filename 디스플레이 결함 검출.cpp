#include <opencv2/opencv.hpp>
#include <windows.h>
#include <commdlg.h>
#include <iostream>
#include <fstream> // CSV 저장용
#include <string>

// 파일 열기 다이얼로그 (이미지 선택)
std::string openFileDialog()
{
    OPENFILENAMEA ofn;
    char szFile[260] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Image Files (*.jpg;*.jpeg;*.png;*.bmp)\0*.jpg;*.jpeg;*.png;*.bmp\0All Files (*.*)\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameA(&ofn)) {
        return std::string(szFile);
    }
    else {
        return "";
    }
}

// 파일 저장 다이얼로그 (CSV 저장용)
std::string saveFileDialog()
{
    OPENFILENAMEA ofn;
    char szFile[260] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "CSV Files (*.csv)\0*.csv\0All Files (*.*)\0*.*\0";
    ofn.lpstrDefExt = "csv"; // 기본 확장자
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

    if (GetSaveFileNameA(&ofn)) {
        return std::string(szFile);
    }
    else {
        return "";
    }
}

// CSV로 결과 저장
void saveDefectsToCSV(const std::vector<cv::Rect>& defects, const std::string& filename)
{
    std::ofstream file(filename);
    file << "Index,X,Y,Width,Height\n";
    int idx = 1;
    for (const auto& rect : defects) {
        file << idx++ << "," << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << "\n";
    }
    file.close();
}

int main()
{
    // 파일 선택
    std::string filepath = openFileDialog();
    if (filepath.empty()) {
        std::cerr << "파일을 선택하지 않았습니다." << std::endl;
        return -1;
    }

    // 이미지 읽기
    cv::Mat image = cv::imread(filepath);
    if (image.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다!" << std::endl;
        return -1;
    }

    // 전처리
    cv::Mat gray, blurred, thresh;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 0);
    cv::adaptiveThreshold(blurred, thresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 11, 2);

    // 결함 검출
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    int defect_count = 0;
    std::vector<cv::Rect> detected_defects;

    for (const auto& contour : contours) {
        double area = cv::contourArea(contour);
        if (area > 50) {
            cv::Rect bbox = cv::boundingRect(contour);
            detected_defects.push_back(bbox);
            cv::rectangle(image, bbox, cv::Scalar(0, 255, 0), 2);
            defect_count++;
        }
    }

    // 결과 출력
    std::cout << "검출된 결함 수: " << defect_count << "개" << std::endl;
    for (size_t i = 0; i < detected_defects.size(); ++i) {
        std::cout << i + 1 << "번 결함 위치 - X: " << detected_defects[i].x
            << ", Y: " << detected_defects[i].y
            << ", Width: " << detected_defects[i].width
            << ", Height: " << detected_defects[i].height << std::endl;
    }

    // CSV 저장 경로 선택
    std::string savepath = saveFileDialog();
    if (!savepath.empty()) {
        saveDefectsToCSV(detected_defects, savepath);
        std::cout << "결함 정보가 저장되었습니다: " << savepath << std::endl;
    }
    else {
        std::cerr << "CSV 저장이 취소되었습니다." << std::endl;
    }

    // 결과 이미지 출력
    cv::imshow("Detected Defects", image);
    cv::imshow("Threshold Image", thresh);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

#pragma once
#include <M5Stack.h>

auto &nextBtn = M5.BtnA;
auto &backBtn = M5.BtnB;
auto &resetBtn = M5.BtnC;
auto &Lcd = M5.Lcd;

namespace config {
static constexpr int loop_period = 10;
static constexpr int task_max = 5;
static constexpr int init_task = 0;
static constexpr auto init_lcd_coler = WHITE;
static constexpr int title_txt_size = 3;
static constexpr int std_txt_size = 2;
static constexpr int next_cursor_x = 40;
static constexpr int next_cursor_y = 210;
static constexpr int end_cursor_x = 0;
static constexpr int end_cursor_y = 80;
static constexpr int fps = 30;
static constexpr int flame_per_ms = 1000 / fps;

}  // namespace config

class Change {
public:
    bool operator()(int value) {
        if (is_first) {
            is_first = false;
            old = value;
            return false;
        } else if (value == old) {
            old = value;
            return false;
        } else {
            old = value;
            return true;
        }
    }

private:
    int old;
    bool is_first = true;
};

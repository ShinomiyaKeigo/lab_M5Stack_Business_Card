#include <M5Stack.h>

#include "config.hpp"

#define SD_CARD_OK false

int btn_count = 0;
int task_count = config::init_task;
bool task_finished = true;

void printNextPage() {
    Lcd.setCursor(config::next_cursor_x, config::next_cursor_y);
    Lcd.setTextSize(config::std_txt_size);
    Lcd.setTextColor(GREENYELLOW);
    Lcd.printf("please push Button A...\n");
}

void init() {
    Lcd.clear(BLACK);
    printNextPage();
    int delay_time = 3000;
    delay(delay_time);

    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void task1() {
    int delay_time = 2500;
    auto back_ground = BLACK;
    auto txt_color1 = GREEN;
    auto txt_color2 = YELLOW;

    Lcd.setCursor(0, 0);
    Lcd.setTextSize(config::title_txt_size);
    Lcd.setTextColor(txt_color1);
    Lcd.clear(back_ground);

    Lcd.printf("= Business Card =\n");
    delay(delay_time);

    Lcd.setTextSize(config::std_txt_size);
    Lcd.setTextColor(txt_color2);

    Lcd.printf("\n\n");
    Lcd.printf("name: Shinomiya Keigo\n");
    delay(delay_time);

    Lcd.printf("from: Shizuoka\n");
    delay(delay_time);

    Lcd.printf("class: 3ER1\n");
    delay(delay_time);

    Lcd.printf("years: 21\n");
    delay(delay_time);

    Lcd.print("hobby: movie, walking\n");

    printNextPage();
    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void task2() {
    int delay_time = 1000;
    auto back_ground = BLACK;
    auto txt_color = PINK;

    Lcd.setCursor(0, 50);
    Lcd.clear(back_ground);
    Lcd.setTextColor(txt_color);

    Lcd.printf("my face photo is\n");

    delay(delay_time);

    printNextPage();
    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void task3() {
    auto back_ground = BLACK;

    Lcd.clear(BLACK);
    Lcd.setCursor(0, 0);

#if SD_CARD_OK
    Lcd.drawJpg(SD, "/face_photo.jpg");
#else
    Lcd.printf("/face_photo.jpg\n");
#endif

    printNextPage();
    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void task4() {
    int delay_time = 1500;
    auto back_ground = NAVY;
    auto txt_color = RED;

    Lcd.clear(back_ground);
    Lcd.setTextSize(config::std_txt_size);
    Lcd.setCursor(0, 0);

    Lcd.printf("I belong to the \n");
    delay(delay_time);
    Lcd.printf("Robot Project.\n");
    delay(delay_time);
    Lcd.printf("I'm with the control team.\n\n");
    delay(delay_time);
    Lcd.printf("I Love Robot!\n");
    delay(delay_time);

    printNextPage();
    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void task5() {
    Lcd.clear(BLACK);
    Lcd.setCursor(0, 0);

#if SD_CARD_OK
    Lcd.drawJpg(SD, "/DR.jpg");
#else
    Lcd.printf("/DR.jpg\n");
#endif
    printNextPage();
    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void task6() {
    Lcd.clear(BLACK);
    Lcd.setCursor(0, 0);
    Lcd.setTextColor(PURPLE);
    Lcd.setTextSize(config::std_txt_size);

    Lcd.printf(
        "I controlled the robot\n"
        "in NHK Robocon 2021.\n"
        "the robot is called \n"
        "\"Mobius\"\n");

    printNextPage();
    bool is_pushed = false;
    while (!is_pushed) {
        M5.update();
        is_pushed = nextBtn.wasReleased();
    }
}

void endTask() {
    int delay_time = 1000;
    auto back_ground = WHITE;
    auto txt_color = BLACK;

    Lcd.clear(back_ground);
    Lcd.setCursor(config::end_cursor_x, config::end_cursor_y);
    Lcd.setTextSize(config::title_txt_size);
    Lcd.setTextColor(txt_color);

    Lcd.printf(
        "   THNKS\n"
        "    FOR \n"
        "  WACHING\n");
    delay(3000);

    Lcd.printf("       ");
    for (int i = 0; i < 5; i++) {
        Lcd.printf(".");
        delay(delay_time);
    }
}

void setup() {
    // setup
    M5.begin();
    init();
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    endTask();
}

void loop() {
// M5.update();
#if SD_CARD_OK
    Lcd.drawJpg(SD, "/parrot1.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot2.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot3.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot4.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot5.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot6.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot7.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot8.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot9.jpg");
    delay(config::flame_per_ms);
    Lcd.drawJpg(SD, "/parrot10.jpg");
    delay(config::flame_per_ms);
#else
    Lcd.clear(BLACK);
    Lcd.setCursor(0, 0);
    Lcd.setTextSize(config::std_txt_size);
    Lcd.setTextColor(GREEN);

    Lcd.println("/parrot1.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot2.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot3.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot4.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot5.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot6.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot7.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot8.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot9.jpg");
    delay(config::flame_per_ms);
    Lcd.println("/parrot10.jpg");
    delay(config::flame_per_ms);
#endif
    // delay(config::loop_period);
}
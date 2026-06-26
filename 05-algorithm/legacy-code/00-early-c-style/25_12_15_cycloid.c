#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600
#define CENTER_Y 300
#define RADIUS 80
#define PI 3.14159265358979323846
#define SPEED 0.05

// 摆线点结构
typedef struct {
    double x;
    double y;
} Point;

// 圆结构
typedef struct {
    double center_x;
    double center_y;
    double radius;
} Circle;

// 生成摆线点
Point get_cycloid_point(double theta, double radius, double offset_x) {
    Point p;
    p.x = offset_x + radius * (theta - sin(theta));
    p.y = CENTER_Y + radius * (1 - cos(theta));
    return p;
}

// 获取圆上的点
Point get_circle_point(Circle circle, double angle) {
    Point p;
    p.x = circle.center_x + circle.radius * cos(angle);
    p.y = circle.center_y + circle.radius * sin(angle);
    return p;
}

int main(int argc, char* argv[]) {
    // 初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL初始化失败: %s\n", SDL_GetError());
        return 1;
    }

    // 创建窗口
    SDL_Window* window = SDL_CreateWindow(
        "摆线生成动画 - Cycloid Generation",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("窗口创建失败: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // 创建渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("渲染器创建失败: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 摆线参数
    double theta = 0.0;
    double offset_x = 100.0;
    int num_points = 0;
    Point cycloid_points[2000];  // 存储摆线点
    Point generating_point;      // 当前生成点

    SDL_Event event;
    int running = 1;

    printf("摆线生成动画\n");
    printf("===============\n");
    printf("数学公式:\n");
    printf("x = r(θ - sinθ)\n");
    printf("y = r(1 - cosθ)\n");
    printf("===============\n");
    printf("控制:\n");
    printf("空格键: 暂停/继续\n");
    printf("R键: 重置动画\n");
    printf("ESC键: 退出程序\n");

    while (running) {
        // 处理事件
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = 0;
                    break;
                case SDLK_SPACE:
                    // 切换暂停状态（这里简化处理，实际需要状态变量）
                    SDL_Delay(100);
                    break;
                case SDLK_r:
                    // 重置动画
                    theta = 0.0;
                    num_points = 0;
                    break;
                }
            }
        }

        // 清除屏幕
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 绘制坐标轴
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderDrawLine(renderer, 0, CENTER_Y, WIDTH, CENTER_Y);  // X轴
        SDL_RenderDrawLine(renderer, offset_x, 0, offset_x, HEIGHT); // 起始线

        // 计算当前圆的位置
        Circle rolling_circle;
        rolling_circle.center_x = offset_x + RADIUS * theta;
        rolling_circle.center_y = CENTER_Y;
        rolling_circle.radius = RADIUS;

        // 生成新的摆线点
        if (theta <= 4 * PI && num_points < 2000) {
            generating_point = get_cycloid_point(theta, RADIUS, offset_x);
            cycloid_points[num_points] = generating_point;
            num_points++;

            // 更新角度
            theta += SPEED;
        }

        // 绘制滚动的圆
        SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
        for (int i = 0; i < 360; i++) {
            double angle1 = i * PI / 180.0;
            double angle2 = (i + 1) * PI / 180.0;

            Point p1 = get_circle_point(rolling_circle, angle1);
            Point p2 = get_circle_point(rolling_circle, angle2);

            SDL_RenderDrawLine(renderer,
                (int)p1.x, (int)p1.y,
                (int)p2.x, (int)p2.y);
        }

        // 绘制圆心和半径
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect center_rect = {
            (int)rolling_circle.center_x - 3,
            (int)rolling_circle.center_y - 3,
            6, 6
        };
        SDL_RenderFillRect(renderer, &center_rect);

        // 绘制半径线
        Point circle_point = get_circle_point(rolling_circle, -theta);
        SDL_RenderDrawLine(renderer,
            (int)rolling_circle.center_x, (int)rolling_circle.center_y,
            (int)circle_point.x, (int)circle_point.y);

        // 绘制生成点（红色）
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect point_rect = {
            (int)generating_point.x - 4,
            (int)generating_point.y - 4,
            8, 8
        };
        SDL_RenderFillRect(renderer, &point_rect);

        // 绘制已生成的摆线轨迹
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (int i = 1; i < num_points; i++) {
            SDL_RenderDrawLine(renderer,
                (int)cycloid_points[i - 1].x, (int)cycloid_points[i - 1].y,
                (int)cycloid_points[i].x, (int)cycloid_points[i].y);
        }

        // 绘制说明文字（通过简单图形表示）
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // 绘制简单的文字提示框
        SDL_Rect info_rect = { 10, 10, 300, 120 };
        SDL_RenderDrawRect(renderer, &info_rect);

        // 显示信息
        char info_text[256];
        snprintf(info_text, sizeof(info_text),
            "θ = %.2fπ (%.2f rad)",
            theta / PI, theta);

        // 这里简化显示，实际可以用SDL_ttf库显示文字
        // 绘制简单的信息线条
        for (int i = 0; i < 5; i++) {
            SDL_RenderDrawLine(renderer, 20, 30 + i * 20, 280, 30 + i * 20);
        }

        // 更新渲染
        SDL_RenderPresent(renderer);

        // 控制帧率
        SDL_Delay(16);  // 约60FPS
    }

    // 清理资源
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
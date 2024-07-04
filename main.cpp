#include "daisy_seed.h"
#include "ili9341_ui_driver.hpp"

ILI9341UiDriver driver;

int main(void)
{
    hw.Init(true);
    driver.Init();

    // Here all the drawing happening in the memory buffer, so no drawing happening at this point.
    driver.Fill(COLOR_BLACK);
    driver.FillRect(Rectangle(100, 100, 50, 50), COLOR_RED);
    driver.DrawRect(Rectangle(100, 120, 50, 50), COLOR_WHITE);

    for(;;)
    {
        // IsRender() checks if DMA is idle (i.e. done transmitting the buffer), Update() initiates the DMA transfer
        if(driver.IsRender())
        {
            driver.Update();
        }
    }
}
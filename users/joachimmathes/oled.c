/* Copyright 2022 Joachim Mathes joachim_mathes@web.de @joachimmathes
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef OLED_ENABLE

#include "oled.h"

uint16_t wpm_timer = 0;
uint16_t current_wpm = 0;
uint8_t y = 31;
float max_wpm = 110.0f; // WPM value at the top of the graph window
uint8_t vertical_count = 0;
bool vertical_lines = false;

void oled_render_logo(void) {
    oled_write_raw_P(split_logo, sizeof(split_logo));
}

void oled_render_wpm(void) {
    current_wpm = get_current_wpm();

    if(timer_elapsed(wpm_timer) > GRAPH_REFRESH_INTERVAL_MS) {

		y = 32 - ((current_wpm / max_wpm) * 32);

		for(int i = 0; i <= GRAPH_LINE_THICKNESS_PX - 1; i++){
			oled_write_pixel(1, y + i, true);
		}

        if(vertical_count == GRAPH_VERTICAL_LINE_INTERVAL) {
            vertical_count = 0;
            while(y <= 32){
                oled_write_pixel(1, y, true);
                y++;
            }
        } else {
            for(int i = 32; i > y; i--){
                if(i % GRAPH_HORIZONTAL_LINE_INTERVAL == 0){
                    oled_write_pixel(1, i, true);
                }
            }
            vertical_count++;
        }

        oled_pan(false);

        wpm_timer = timer_read();
    }

    if(current_wpm > 0) {
        oled_set_cursor(13, 3);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(current_wpm, '0'), false);
    }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
      oled_render_wpm();
    } else {
      oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

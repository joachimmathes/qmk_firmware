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

#include "joachimmathes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER0] = LAYOUT_ortho_4x10_to_ortho_4x12_wrapper(LAYOUT_LAYER0),
    [LAYER1] = LAYOUT_ortho_4x10_to_ortho_4x12_wrapper(LAYOUT_LAYER1),
    [LAYER2] = LAYOUT_ortho_4x10_to_ortho_4x12_wrapper(LAYOUT_LAYER2),
    [LAYER3] = LAYOUT_ortho_4x10_to_ortho_4x12_wrapper(LAYOUT_LAYER3)
};

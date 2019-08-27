#include "timing.h"

namespace Vga
{

Timing const timing_800x600_56hz =
{
	.pixel_frequency_mhz = 36.0,

	.horizPixels = 800,
    .horizSyncPolarity = Timing::Polarity::positive,
    .horizWholeLine = 1024,
    .horizSyncPulse = 72,
    .horizStartDraw = 72 - 24,
	.horizLead = -90,

	.verticalPixels = 600,
    .verticalSyncPolarity = Timing::Polarity::positive,
    .verticalWholeFrame = 625,
    .verticalSyncPulse = 2,
    .verticalStartLine = 25
};

} // namespace Vga

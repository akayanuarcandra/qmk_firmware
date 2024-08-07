#define FP_POINTING_COMBINED_SCROLLING_LEFT false
#define FP_POINTING_COMBINED_SNIPING_LEFT true

#ifdef DEBOUNCE
  #undef DEBOUNCE
  #define DEBOUNCE 12
#endif

// --------------------------- Other keyboard build specific configs ------------------------------
#ifdef XIMI_TRACKPOINT_BUILD
#define MASTER_RIGHT
#define PS2_CLOCK_PIN GP6
#define PS2_DATA_PIN  GP5
#endif
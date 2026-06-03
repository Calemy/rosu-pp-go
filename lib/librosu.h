#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct BeatmapHandle BeatmapHandle;

typedef struct CalculatorParams CalculatorParams;

typedef struct CalculatorResult {
  double pp;
  double pp_aim;
  double pp_speed;
  double pp_flashlight;
  double pp_acc;
  double stars;
} CalculatorResult;

struct BeatmapHandle *load_beatmap(const char *path);

const struct CalculatorResult *calculate_beatmap(struct BeatmapHandle *handle,
                                                 const struct CalculatorParams *params);

struct CalculatorParams *create_calculator_params(void);

void params_set_mode(struct CalculatorParams *params, uint8_t mode);

void params_set_combo(struct CalculatorParams *params, uint32_t combo);

void params_set_n300(struct CalculatorParams *params, uint32_t n300);

void params_set_n100(struct CalculatorParams *params, uint32_t n100);

void params_set_n50(struct CalculatorParams *params, uint32_t n50);

void params_set_nmiss(struct CalculatorParams *params, uint32_t nmiss);

void params_set_ngeki(struct CalculatorParams *params, uint32_t ngeki);

void params_set_nkatu(struct CalculatorParams *params, uint32_t nkatu);

void params_set_mods(struct CalculatorParams *params, uint32_t mods);

void params_set_accuracy(struct CalculatorParams *params, double accuracy);

void free_beatmap(struct BeatmapHandle *handle);


#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum rosu_pp_FfiResult {
  rosu_pp_FfiResult_Ok = 0,
  rosu_pp_FfiResult_Done = 1,
  rosu_pp_FfiResult_ParseError = 2,
  rosu_pp_FfiResult_NullPointer = 3,
  rosu_pp_FfiResult_InvalidArgument = 4,
  rosu_pp_FfiResult_TooSuspicious = 5,
  rosu_pp_FfiResult_None = 6,
} rosu_pp_FfiResult;

typedef enum rosu_pp_GameMode {
  rosu_pp_GameMode_Osu = 0,
  rosu_pp_GameMode_Taiko = 1,
  rosu_pp_GameMode_Catch = 2,
  rosu_pp_GameMode_Mania = 3,
} rosu_pp_GameMode;

typedef struct rosu_pp_InspectDifficultyHandle rosu_pp_InspectDifficultyHandle;

typedef struct rosu_pp_BeatmapAttributesHandle rosu_pp_BeatmapAttributesHandle;

typedef struct rosu_pp_BeatmapAttributesBuilderHandle rosu_pp_BeatmapAttributesBuilderHandle;

typedef struct rosu_pp_BeatmapHandle rosu_pp_BeatmapHandle;

typedef struct rosu_pp_GradualDifficultyHandle rosu_pp_GradualDifficultyHandle;

typedef struct rosu_pp_GradualPerformanceHandle rosu_pp_GradualPerformanceHandle;

typedef struct rosu_pp_ModsHandle rosu_pp_ModsHandle;

typedef struct rosu_pp_DifficultyHandle rosu_pp_DifficultyHandle;

typedef struct rosu_pp_PerformanceHandle rosu_pp_PerformanceHandle;

typedef struct rosu_pp_AdjustedBeatmapAttributes {
  double ar;
  float cs;
  float hp;
  double od;
} rosu_pp_AdjustedBeatmapAttributes;

typedef struct rosu_pp_HitWindows {
  double ar;
  double od_perfect;
  double od_great;
  double od_good;
  double od_ok;
  double od_meh;
} rosu_pp_HitWindows;

typedef struct rosu_pp_StrainsData {
  int32_t mode;
  double section_len;
  uintptr_t len;
  const double *aim;
  const double *aim_no_sliders;
  const double *speed;
  const double *flashlight;
  const double *stamina;
  const double *rhythm;
  const double *color;
  const double *reading;
  const double *single_color_stamina;
  const double *movement;
  const double *strains;
} rosu_pp_StrainsData;

typedef struct rosu_pp_ScoreState {
  uint32_t max_combo;
  uint32_t osu_large_tick_hits;
  uint32_t osu_small_tick_hits;
  uint32_t slider_end_hits;
  uint32_t n_geki;
  uint32_t n_katu;
  uint32_t n300;
  uint32_t n100;
  uint32_t n50;
  uint32_t misses;
  uint32_t legacy_total_score;
  bool legacy_total_score_valid;
} rosu_pp_ScoreState;

typedef struct rosu_pp_DifficultyAttributes {
  int32_t mode;
  double stars;
  uint32_t max_combo;
  double aim;
  double speed;
  double flashlight;
  double stamina;
  double rhythm;
  double color;
  double reading;
  double ar;
  double hp;
  double great_hit_window;
  double ok_hit_window;
  double meh_hit_window;
  uint32_t n_circles;
  uint32_t n_sliders;
  uint32_t n_large_ticks;
  uint32_t n_spinners;
  uint32_t n_objects;
  double aim_difficult_slider_count;
  double slider_factor;
  double aim_top_weighted_slider_factor;
  double speed_top_weighted_slider_factor;
  double speed_note_count;
  double aim_difficult_strain_count;
  double speed_difficult_strain_count;
  double nested_score_per_object;
  double legacy_score_base_multiplier;
  double maximum_legacy_combo_score;
  double mono_stamina_factor;
  double mechanical_difficulty;
  double consistency_factor;
  double preempt;
  uint32_t n_fruits;
  uint32_t n_droplets;
  uint32_t n_tiny_droplets;
  uint32_t n_hold_notes;
  bool is_convert;
} rosu_pp_DifficultyAttributes;

typedef struct rosu_pp_PerformanceAttributes {
  double pp;
  double pp_acc;
  double pp_aim;
  double pp_speed;
  double pp_flashlight;
  double pp_difficulty;
  double effective_miss_count;
  double speed_deviation;
  double combo_based_estimated_miss_count;
  double score_based_estimated_miss_count;
  double aim_estimated_slider_breaks;
  double speed_estimated_slider_breaks;
  double estimated_unstable_rate;
  struct rosu_pp_DifficultyAttributes difficulty;
} rosu_pp_PerformanceAttributes;

float rosu_pp_beatmap_attrs_ar(const struct rosu_pp_BeatmapAttributesHandle *handle);

struct rosu_pp_BeatmapAttributesBuilderHandle *rosu_pp_beatmap_attrs_builder_new(void);

struct rosu_pp_InspectDifficultyHandle *rosu_pp_difficulty_inspect_new(struct rosu_pp_DifficultyHandle *handle);

enum rosu_pp_FfiResult rosu_pp_beatmap_from_path(const char *path, struct rosu_pp_BeatmapHandle * *out);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_apply_clock_rate(const struct rosu_pp_BeatmapAttributesHandle *handle, struct rosu_pp_AdjustedBeatmapAttributes *out);

struct rosu_pp_DifficultyHandle *rosu_pp_difficulty_new(void);

struct rosu_pp_GradualDifficultyHandle *rosu_pp_gradual_difficulty_new(struct rosu_pp_DifficultyHandle *difficulty, const struct rosu_pp_BeatmapHandle *map);

struct rosu_pp_GradualPerformanceHandle *rosu_pp_gradual_performance_new(struct rosu_pp_DifficultyHandle *difficulty, const struct rosu_pp_BeatmapHandle *map);

float rosu_pp_beatmap_attrs_od(const struct rosu_pp_BeatmapAttributesHandle *handle);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_map(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, const struct rosu_pp_BeatmapHandle *map);

enum rosu_pp_FfiResult rosu_pp_mods_from_acronym(const char *s, struct rosu_pp_ModsHandle * *out);

struct rosu_pp_ModsHandle *rosu_pp_inspect_difficulty_mods(const struct rosu_pp_InspectDifficultyHandle *handle);

struct rosu_pp_DifficultyHandle *rosu_pp_difficulty_clone(const struct rosu_pp_DifficultyHandle *handle);

struct rosu_pp_PerformanceHandle *rosu_pp_performance_new(const struct rosu_pp_BeatmapHandle *map);

float rosu_pp_beatmap_attrs_cs(const struct rosu_pp_BeatmapAttributesHandle *handle);

const char *rosu_pp_mode_to_str(enum rosu_pp_GameMode mode);

enum rosu_pp_FfiResult rosu_pp_gradual_difficulty_next(struct rosu_pp_GradualDifficultyHandle *handle, struct rosu_pp_DifficultyAttributes *out);

enum rosu_pp_FfiResult rosu_pp_gradual_performance_next(struct rosu_pp_GradualPerformanceHandle *handle, const struct rosu_pp_ScoreState *state, struct rosu_pp_PerformanceAttributes *out);

float rosu_pp_beatmap_attrs_hp(const struct rosu_pp_BeatmapAttributesHandle *handle);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_ar(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, float ar, bool fixed);

enum rosu_pp_FfiResult rosu_pp_beatmap_from_bytes(const uint8_t *bytes, uintptr_t len, struct rosu_pp_BeatmapHandle * *out);

enum rosu_pp_FfiResult rosu_pp_difficulty_mods(struct rosu_pp_DifficultyHandle *handle, const struct rosu_pp_ModsHandle *mods);

struct rosu_pp_PerformanceHandle *rosu_pp_performance_new_from_attrs(const struct rosu_pp_PerformanceAttributes *attrs);

struct rosu_pp_ScoreState rosu_pp_score_state_new(void);

double rosu_pp_beatmap_attrs_clock_rate(const struct rosu_pp_BeatmapAttributesHandle *handle);

void rosu_pp_gradual_difficulty_free(struct rosu_pp_GradualDifficultyHandle *handle);

enum rosu_pp_FfiResult rosu_pp_mode_from_str(const char *s, enum rosu_pp_GameMode *out);

enum rosu_pp_FfiResult rosu_pp_mods_from_json_with_mode(const char *s, bool deny_unknown_fields, enum rosu_pp_GameMode mode, struct rosu_pp_ModsHandle * *out);

void rosu_pp_gradual_performance_free(struct rosu_pp_GradualPerformanceHandle *handle);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_od(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, float od, bool fixed);

struct rosu_pp_PerformanceHandle *rosu_pp_performance_new_from_diff_attrs(const struct rosu_pp_DifficultyAttributes *attrs);

uint32_t rosu_pp_score_state_total_hits(const struct rosu_pp_ScoreState *state, enum rosu_pp_GameMode mode);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_hit_windows(const struct rosu_pp_BeatmapAttributesHandle *handle, struct rosu_pp_HitWindows *out);

void rosu_pp_strains_free(struct rosu_pp_StrainsData *handle);

enum rosu_pp_FfiResult rosu_pp_difficulty_passed_objects(struct rosu_pp_DifficultyHandle *handle, uint32_t passed_objects);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_cs(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, float cs, bool fixed);

enum rosu_pp_FfiResult rosu_pp_difficulty_clock_rate(struct rosu_pp_DifficultyHandle *handle, double clock_rate);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_passed_objects(const struct rosu_pp_InspectDifficultyHandle *handle, uint32_t *out);

int32_t rosu_pp_beatmap_version(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_clock_rate(const struct rosu_pp_InspectDifficultyHandle *handle, double *out);

enum rosu_pp_FfiResult rosu_pp_performance_mods(struct rosu_pp_PerformanceHandle *handle, const struct rosu_pp_ModsHandle *mods);

void rosu_pp_beatmap_attrs_free(struct rosu_pp_BeatmapAttributesHandle *handle);

enum rosu_pp_GameMode rosu_pp_beatmap_mode(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_hardrock_offsets(const struct rosu_pp_InspectDifficultyHandle *handle, bool *out);

float rosu_pp_beatmap_ar(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_lazer(const struct rosu_pp_InspectDifficultyHandle *handle, bool *out);

float rosu_pp_beatmap_cs(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_ar(const struct rosu_pp_InspectDifficultyHandle *handle, float *out, bool *fixed);

float rosu_pp_beatmap_hp(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_cs(const struct rosu_pp_InspectDifficultyHandle *handle, float *out, bool *fixed);

float rosu_pp_beatmap_od(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_hp(const struct rosu_pp_InspectDifficultyHandle *handle, float *out, bool *fixed);

enum rosu_pp_FfiResult rosu_pp_mods_from_json(const char *s, bool deny_unknown_fields, struct rosu_pp_ModsHandle * *out);

double rosu_pp_beatmap_slider_multiplier(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_inspect_difficulty_od(const struct rosu_pp_InspectDifficultyHandle *handle, float *out, bool *fixed);

double rosu_pp_beatmap_slider_tick_rate(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_difficulty_ar(struct rosu_pp_DifficultyHandle *handle, float ar, bool fixed);

float rosu_pp_beatmap_stack_leniency(const struct rosu_pp_BeatmapHandle *handle);

bool rosu_pp_beatmap_is_convert(const struct rosu_pp_BeatmapHandle *handle);

uintptr_t rosu_pp_beatmap_hit_object_count(const struct rosu_pp_BeatmapHandle *handle);

double rosu_pp_beatmap_total_break_time(const struct rosu_pp_BeatmapHandle *handle);

double rosu_pp_beatmap_bpm(const struct rosu_pp_BeatmapHandle *handle);

uintptr_t rosu_pp_beatmap_timing_point_count(const struct rosu_pp_BeatmapHandle *handle);

uintptr_t rosu_pp_beatmap_difficulty_point_count(const struct rosu_pp_BeatmapHandle *handle);

uintptr_t rosu_pp_beatmap_effect_point_count(const struct rosu_pp_BeatmapHandle *handle);

uintptr_t rosu_pp_beatmap_break_count(const struct rosu_pp_BeatmapHandle *handle);

uintptr_t rosu_pp_beatmap_hit_sound_count(const struct rosu_pp_BeatmapHandle *handle);

void rosu_pp_inspect_difficulty_free(struct rosu_pp_InspectDifficultyHandle *handle);

enum rosu_pp_FfiResult rosu_pp_difficulty_cs(struct rosu_pp_DifficultyHandle *handle, float cs, bool fixed);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_hp(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, float hp, bool fixed);

enum rosu_pp_FfiResult rosu_pp_difficulty_hp(struct rosu_pp_DifficultyHandle *handle, float hp, bool fixed);

enum rosu_pp_FfiResult rosu_pp_beatmap_check_suspicion(const struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_difficulty_od(struct rosu_pp_DifficultyHandle *handle, float od, bool fixed);

enum rosu_pp_FfiResult rosu_pp_performance_passed_objects(struct rosu_pp_PerformanceHandle *handle, uint32_t passed_objects);

struct rosu_pp_ModsHandle *rosu_pp_mods_from_bits(uint32_t bits);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_mods(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, const struct rosu_pp_ModsHandle *mods);

enum rosu_pp_FfiResult rosu_pp_performance_clock_rate(struct rosu_pp_PerformanceHandle *handle, double clock_rate);

void rosu_pp_beatmap_free(struct rosu_pp_BeatmapHandle *handle);

enum rosu_pp_FfiResult rosu_pp_difficulty_hardrock_offsets(struct rosu_pp_DifficultyHandle *handle, bool hardrock_offsets);

uint32_t rosu_pp_mods_to_bits(const struct rosu_pp_ModsHandle *mods);

enum rosu_pp_FfiResult rosu_pp_performance_ar(struct rosu_pp_PerformanceHandle *handle, float ar, bool fixed);

enum rosu_pp_FfiResult rosu_pp_difficulty_lazer(struct rosu_pp_DifficultyHandle *handle, bool lazer);

enum rosu_pp_FfiResult rosu_pp_performance_cs(struct rosu_pp_PerformanceHandle *handle, float cs, bool fixed);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_clock_rate(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, double clock_rate);

char *rosu_pp_mods_to_string(const struct rosu_pp_ModsHandle *mods);

enum rosu_pp_FfiResult rosu_pp_performance_hp(struct rosu_pp_PerformanceHandle *handle, float hp, bool fixed);

enum rosu_pp_FfiResult rosu_pp_difficulty_calculate(struct rosu_pp_DifficultyHandle *handle, const struct rosu_pp_BeatmapHandle *map, struct rosu_pp_DifficultyAttributes *out);

enum rosu_pp_FfiResult rosu_pp_performance_od(struct rosu_pp_PerformanceHandle *handle, float od, bool fixed);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_mode(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, enum rosu_pp_GameMode mode, bool is_convert);

void rosu_pp_mods_free_string(char *s);

enum rosu_pp_FfiResult rosu_pp_performance_hardrock_offsets(struct rosu_pp_PerformanceHandle *handle, bool hardrock_offsets);

enum rosu_pp_FfiResult rosu_pp_performance_lazer(struct rosu_pp_PerformanceHandle *handle, bool lazer);

void rosu_pp_mods_free(struct rosu_pp_ModsHandle *handle);

enum rosu_pp_FfiResult rosu_pp_difficulty_checked_calculate(struct rosu_pp_DifficultyHandle *handle, const struct rosu_pp_BeatmapHandle *map, struct rosu_pp_DifficultyAttributes *out);

enum rosu_pp_FfiResult rosu_pp_performance_accuracy(struct rosu_pp_PerformanceHandle *handle, double accuracy);

enum rosu_pp_FfiResult rosu_pp_beatmap_attrs_builder_difficulty(struct rosu_pp_BeatmapAttributesBuilderHandle *handle, const struct rosu_pp_DifficultyHandle *difficulty);

enum rosu_pp_FfiResult rosu_pp_performance_misses(struct rosu_pp_PerformanceHandle *handle, uint32_t misses);

enum rosu_pp_FfiResult rosu_pp_performance_combo(struct rosu_pp_PerformanceHandle *handle, uint32_t combo);

enum rosu_pp_FfiResult rosu_pp_performance_large_tick_hits(struct rosu_pp_PerformanceHandle *handle, uint32_t large_tick_hits);

struct rosu_pp_StrainsData *rosu_pp_difficulty_strains(struct rosu_pp_DifficultyHandle *handle, const struct rosu_pp_BeatmapHandle *map);

struct rosu_pp_BeatmapAttributesHandle *rosu_pp_beatmap_attrs_builder_build(struct rosu_pp_BeatmapAttributesBuilderHandle *handle);

enum rosu_pp_FfiResult rosu_pp_performance_small_tick_hits(struct rosu_pp_PerformanceHandle *handle, uint32_t small_tick_hits);

enum rosu_pp_FfiResult rosu_pp_performance_slider_end_hits(struct rosu_pp_PerformanceHandle *handle, uint32_t slider_end_hits);

enum rosu_pp_FfiResult rosu_pp_performance_n300(struct rosu_pp_PerformanceHandle *handle, uint32_t n300);

void rosu_pp_beatmap_attrs_builder_free(struct rosu_pp_BeatmapAttributesBuilderHandle *handle);

void rosu_pp_difficulty_free(struct rosu_pp_DifficultyHandle *handle);

enum rosu_pp_FfiResult rosu_pp_performance_n100(struct rosu_pp_PerformanceHandle *handle, uint32_t n100);

enum rosu_pp_FfiResult rosu_pp_performance_n50(struct rosu_pp_PerformanceHandle *handle, uint32_t n50);

enum rosu_pp_FfiResult rosu_pp_performance_n_geki(struct rosu_pp_PerformanceHandle *handle, uint32_t n_geki);

enum rosu_pp_FfiResult rosu_pp_performance_n_katu(struct rosu_pp_PerformanceHandle *handle, uint32_t n_katu);

enum rosu_pp_FfiResult rosu_pp_performance_legacy_total_score(struct rosu_pp_PerformanceHandle *handle, uint32_t legacy_total_score);

enum rosu_pp_FfiResult rosu_pp_performance_hitresult_priority(struct rosu_pp_PerformanceHandle *handle, uint32_t priority);

enum rosu_pp_FfiResult rosu_pp_performance_checked_calculate(struct rosu_pp_PerformanceHandle *handle, struct rosu_pp_PerformanceAttributes *out);

enum rosu_pp_FfiResult rosu_pp_performance_state(struct rosu_pp_PerformanceHandle *handle, const struct rosu_pp_ScoreState *state);

enum rosu_pp_FfiResult rosu_pp_performance_calculate(struct rosu_pp_PerformanceHandle *handle, struct rosu_pp_PerformanceAttributes *out);

void rosu_pp_performance_free(struct rosu_pp_PerformanceHandle *handle);
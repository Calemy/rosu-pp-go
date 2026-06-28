package rosuppgo

import "testing"

func TestLoadBeatmap(t *testing.T) {
	beatmap, err := BeatmapFromPath("75.osu")
	if err != nil {
		t.Error(err)
		return
	}

	defer beatmap.Free()
	t.Log("Success")
}

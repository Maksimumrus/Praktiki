package com.example.pr_2;

import java.io.Serializable;

public class Settings implements Serializable {
    private String color;
    private int volume;
    private int difficulty;

    public Settings(String color, int volume, int difficulty) {
        this.color = color;
        this.volume = volume;
        this.difficulty = difficulty;
    }

    public String getColor() {
        return color;
    }

    public int getVolume() {
        return volume;
    }

    public int getDifficulty() {
        return difficulty;
    }
}
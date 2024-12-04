package com.example.pianoroll;

import android.media.MediaParser;
import android.media.MediaPlayer;
import android.media.MediaScannerConnection;
import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;

import androidx.core.view.WindowCompat;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.example.pianoroll.databinding.ActivityMainBinding;

import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity {
    
    private MediaPlayer a_note;
    private MediaPlayer am_note;
    private MediaPlayer b_note;
    private MediaPlayer c2_note;
    private MediaPlayer c_note;
    private MediaPlayer cm_note;
    private MediaPlayer d_note;
    private MediaPlayer dm_note;
    private MediaPlayer e_note;
    private MediaPlayer f_note;
    private MediaPlayer fm_note;
    private MediaPlayer g_note;
    private MediaPlayer gm_note;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        View ButtonC = findViewById(R.id.c);
        View ButtonD = findViewById(R.id.d);
        View ButtonG = findViewById(R.id.g);
        View ButtonA = findViewById(R.id.a);
        View ButtonF = findViewById(R.id.f);
        View ButtonE = findViewById(R.id.e);
        View ButtonB = findViewById(R.id.b);
        View ButtonCC = findViewById(R.id.ff);

        View ButtonCRight = findViewById(R.id.CCC);
        View ButtonDRight = findViewById(R.id.DDD);
        View ButtonARight = findViewById(R.id.AAA);
        View ButtonFRight = findViewById(R.id.FFF);
        View ButtonGRight = findViewById(R.id.GGG);

        a_note = MediaPlayer.create(this, R.raw.a_note);
        am_note = MediaPlayer.create(this ,R.raw.am_note);
        b_note = MediaPlayer.create(this ,R.raw.b_note);
        c2_note = MediaPlayer.create(this ,R.raw.c2_note);
        c_note = MediaPlayer.create(this, R.raw.c_note);
        cm_note = MediaPlayer.create(this, R.raw.cm_note);
        d_note = MediaPlayer.create(this, R.raw.d_note);
        dm_note = MediaPlayer.create(this, R.raw.dm_note);
        e_note = MediaPlayer.create(this, R.raw.e_note);
        f_note = MediaPlayer.create(this, R.raw.f_note);
        fm_note = MediaPlayer.create(this,R.raw.fm_note);
        g_note = MediaPlayer.create(this, R.raw.g_note);
        gm_note = MediaPlayer.create(this,R.raw.gm_note);

        ButtonCC.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!c_note.isPlaying()){
                    c_note.start();
                }
                else {
                    c_note.pause();
                }
            }
        });

        ButtonARight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!am_note.isPlaying()){
                    am_note.start();
                }
                else {
                    am_note.pause();
                }
            }
        });

        ButtonGRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!gm_note.isPlaying()){
                    gm_note.start();
                }
                else {
                    gm_note.pause();
                }
            }
        });

        ButtonFRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!fm_note.isPlaying()){
                    fm_note.start();
                }
                else {
                    fm_note.pause();
                }
            }
        });

        ButtonDRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!dm_note.isPlaying()){
                    dm_note.start();
                }
                else {
                    dm_note.pause();
                }
            }
        });

        ButtonCRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!c2_note.isPlaying()){
                    c2_note.start();
                }
                else {
                    c2_note.pause();
                }
            }
        });

        ButtonC.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!c_note.isPlaying()){
                    c_note.start();
                }
                else {
                    c_note.pause();
                }
            }
        });

        ButtonB.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!b_note.isPlaying()){
                    b_note.start();
                }
                else {
                    b_note.pause();
                }
            }
        });

        ButtonA.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!a_note.isPlaying()){
                    a_note.start();
                }
                else {
                    a_note.pause();
                }
            }
        });

        ButtonG.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!g_note.isPlaying()){
                    g_note.start();
                }
                else {
                    g_note.pause();
                }
            }
        });

        ButtonF.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!f_note.isPlaying()){
                    f_note.start();
                }
                else {
                    f_note.pause();
                }
            }
        });

        ButtonE.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!e_note.isPlaying()){
                    e_note.start();
                }
                else {
                    e_note.pause();
                }
            }
        });

        ButtonD.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!d_note.isPlaying()){
                    d_note.start();
                }
                else {
                    d_note.pause();
                }
            }
        });

        ButtonC.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!c_note.isPlaying()){
                    c_note.start();
                }
                else {
                    c_note.pause();
                }
            }
        });

        ButtonCRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!cm_note.isPlaying()){
                    cm_note.start();
                }
                else {
                    cm_note.pause();
                }
            }
        });



    }

}
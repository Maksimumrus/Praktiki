package com.example.pr_2;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.RadioGroup;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.TextView;

public class SettingsActivity extends AppCompatActivity {
    private Spinner spinnerColors;
    private SeekBar BarVolume;
    private RadioGroup radioGroupDifficulty;
    private TextView VolumeLabel;

    private int selectedVolume = 50;
    private String selectedColor;
    private int selectedDifficulty = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        spinnerColors = findViewById(R.id.Spinnercolor);
        BarVolume = findViewById(R.id.BarVolume);
        radioGroupDifficulty = findViewById(R.id.radioGroupDifficulty);
        VolumeLabel = findViewById(R.id.VLabel);
        Button btnSaveSettings = findViewById(R.id.btnSaveSettings);

        spinnerColors.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                selectedColor = parent.getItemAtPosition(position).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) { }
        });

        BarVolume.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser ) {
                selectedVolume = progress;
                VolumeLabel.setText("Громкость: " + selectedVolume);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) { }
        });

        radioGroupDifficulty.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                if (checkedId == R.id.rbEasy) {
                    selectedDifficulty = 1;
                } else if (checkedId == R.id.rbMedium) {
                    selectedDifficulty = 2;
                } else if (checkedId == R.id.rbHard) {
                    selectedDifficulty = 3;
                }
            }
        });

        btnSaveSettings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Settings settings = new Settings(selectedColor, selectedVolume, selectedDifficulty);


                Intent intent = new Intent();
                intent.putExtra("settings", settings);
                setResult(RESULT_OK, intent);
                finish();
            }
        });
    }
}
{
  "targets": [
    {
      "target_name": "FillZero",
      "sources": [ "/src/FillZero.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}

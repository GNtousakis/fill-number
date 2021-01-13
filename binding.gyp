{
  "targets": [
    {
      "target_name": "FillNumber",
      "sources": [ "/src/FillNumber.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}

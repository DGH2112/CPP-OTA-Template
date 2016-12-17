object frameAppOptions: TframeAppOptions
  Left = 0
  Top = 0
  Width = 264
  Height = 164
  TabOrder = 0
  DesignSize = (
    264
    164)
  object chkEnabled: TCheckBox
    Left = 3
    Top = 3
    Width = 258
    Height = 17
    Anchors = [akLeft, akTop, akRight]
    Caption = '&Enabled'
    TabOrder = 0
    ExplicitWidth = 549
  end
  object gbxAutoSaveOptions: TGroupBox
    Left = 3
    Top = 26
    Width = 258
    Height = 135
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Auto Save &Options'
    TabOrder = 1
    ExplicitWidth = 549
    ExplicitHeight = 313
    object lblInterval: TLabel
      Left = 16
      Top = 32
      Width = 38
      Height = 13
      Caption = '&Interval'
      FocusControl = edtInterval
    end
    object edtInterval: TEdit
      Left = 96
      Top = 29
      Width = 49
      Height = 21
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object udInterval: TUpDown
      Left = 145
      Top = 29
      Width = 16
      Height = 21
      Associate = edtInterval
      Min = 10
      Max = 3600
      TabOrder = 1
    end
    object chkPrompt: TCheckBox
      Left = 16
      Top = 56
      Width = 145
      Height = 17
      Caption = '&Prompt'
      TabOrder = 2
    end
  end
end

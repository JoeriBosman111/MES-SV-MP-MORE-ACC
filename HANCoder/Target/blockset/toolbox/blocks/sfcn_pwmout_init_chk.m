%%***************************************************************************************
%% file         sfcn_pwmout_init_chk.m
%% brief        Block parameter check function.
%%
%%---------------------------------------------------------------------------------------
%%                          C O P Y R I G H T
%%---------------------------------------------------------------------------------------
%%  Copyright 2019 (c) by HAN Automotive     http://www.han.nl     All rights reserved
%%
%%---------------------------------------------------------------------------------------
%%                            L I C E N S E
%%---------------------------------------------------------------------------------------
%% Permission is hereby granted, free of charge, to any person obtaining a copy of this
%% software and associated documentation files (the "Software"), to deal in the Software
%% without restriction, including without limitation the rights to use, copy, modify, merge,
%% publish, distribute, sublicense, and/or sell copies of the Software, and to permit
%% persons to whom the Software is furnished to do so, subject to the following conditions:
%%
%% The above copyright notice and this permission notice shall be included in all copies or
%% substantial portions of the Software.
%%
%% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
%% INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
%% PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
%% FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
%% OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
%% DEALINGS IN THE SOFTWARE.
%%
%%***************************************************************************************
function sfcn_pwmout_init_chk()
  % determine the number of pwm init blocks
  num_pwm_out_blocks = length(find_system(bdroot, 'MaskType', 'Pulse Width Modulation Initialization'));
  % only need to run check if there are more than 1 
  if num_pwm_out_blocks > 1
    % store blocks in array
    blocks = find_system(bdroot, 'MaskType', 'Pulse Width Modulation Initialization');
    % loop through all pwm out blocks blocks
    for i = 1:num_pwm_out_blocks
      % obtain the pwm module parameter value
      maskValuesCurrent = get_param(blocks(i), 'MaskValues');
      % extract the timer module, which is formated as TIMx
      timerCurrent = strtok(maskValuesCurrent{1}{1}, ':');
      % now loop through the blocks again to see if this one is already used elsewhere
      for j = 1:num_pwm_out_blocks
        if j ~= i
          % obtain the pwm module parameter value
          maskValuesCheck = get_param(blocks(j), 'MaskValues');
          % extract the timer module, which is formated as TIMx
          timerCheck = strtok(maskValuesCheck{1}{1}, ':');
          % check if the mask string for the output pin are the same
          if strcmp(timerCurrent, timerCheck) == 1
            message = strcat('Error: A PWM Init block for the same timer (', timerCurrent, ') is already present in the model. Select a different timer or remove the duplicate block.');
            errordlg(message, 'Block error');
            % no need to continue because error was encountered
            return;
          end
        end
      end
    end
  end
  % still here so there are no duplicate pwm outputs. now check if a configured timer 
  % module for a PWM output is not already used in a quadrature encoder module.
  num_quad_enc_blocks = length(find_system(bdroot, 'MaskType', 'Quadrature Encoder Inputs'));
  % only need to check if there is at least one of each
  if (num_quad_enc_blocks > 0) && (num_pwm_out_blocks > 0)
    % store blocks in array
    pwm_out_blocks = find_system(bdroot, 'MaskType', 'Pulse Width Modulation Initialization');
    quad_enc_blocks = find_system(bdroot, 'MaskType', 'Quadrature Encoder Inputs');
    % loop through all pwm outputs blocks
    for i = 1:num_pwm_out_blocks
      % obtain the pwm module parameter value
      maskValuesCurrent = get_param(pwm_out_blocks(i), 'MaskValues');
      % extract the timer module, which is formated as TIMx
      timerCurrent = strtok(maskValuesCurrent{1}{1}, ':');
      % now loop through the quad encoder blocks to see if this one is already used elsewhere
      for j = 1:num_quad_enc_blocks
        % obtain the pwm module parameter value
        maskValuesCheck = get_param(quad_enc_blocks(j), 'MaskValues');
        % extract the timer module, which is formated as TIMx
        timerCheck = strtok(maskValuesCheck{1}{1}, ':');
        % check if the mask string for the output pin are the same
        if strcmp(timerCurrent, timerCheck) == 1
          message = strcat('Error: A Quadrature Encode Module block for the same timer (', timerCurrent, ') is already present in the model. Select a different timer or remove the Quadrature Encoder Module block.');
          errordlg(message, 'Block error');
          % no need to continue because error was encountered
          return;
        end
      end
    end
  end
  % still here so there are no duplicate pwm outputs. now check if a configured timer 
  % module for a PWM output is not already used in a timer in module.
  num_timer_in_blocks = length(find_system(bdroot, 'MaskType', 'Timer Input Get'));
  % only need to check if there is at least one of each
  if (num_timer_in_blocks > 0) && (num_pwm_out_blocks > 0)
    % store blocks in array
    pwm_out_blocks = find_system(bdroot, 'MaskType', 'Pulse Width Modulation Initialization');
    timer_in_blocks = find_system(bdroot, 'MaskType', 'Timer Input Get');
    % loop through all pwm outputs blocks
    for i = 1:num_pwm_out_blocks
      % obtain the pwm module parameter value
      maskValuesCurrent = get_param(pwm_out_blocks(i), 'MaskValues');
      % extract the timer module, which is formated as TIMx
      timerCurrent = strtok(maskValuesCurrent{1}{1}, ':');
      % now loop through the quad encoder blocks to see if this one is already used elsewhere
      for j = 1:num_timer_in_blocks
        % obtain the pwm module parameter value
        maskValuesCheck = get_param(timer_in_blocks(j), 'MaskValues');
        % extract the timer module, which is formated as TIMx
        timerCheck = strtok(maskValuesCheck{1}{1}, ':');
        % check if the mask string for the output pin are the same
        if strcmp(timerCurrent, timerCheck) == 1
          message = strcat('Error: A Timer Input Get block for the same timer (', timerCurrent, ') is already present in the model. Select a different timer or remove the Timer Input Get block.');
          errordlg(message, 'Block error');
          % no need to continue because error was encountered
          return;
        end
      end
    end
  end
  % still here so there are no duplicate timer in outputs. now check if a configured timer 
  % module for a PWM output is not already used in a timer in IRQ module.
  num_timer_in_blocks = length(find_system(bdroot, 'MaskType', 'Timer Input IRQ'));
  % only need to check if there is at least one of each
  if (num_timer_in_blocks > 0) && (num_pwm_out_blocks > 0)
    % store blocks in array
    pwm_out_blocks = find_system(bdroot, 'MaskType', 'Pulse Width Modulation Initialization');
    timer_in_blocks = find_system(bdroot, 'MaskType', 'Timer Input IRQ');
    % loop through all pwm outputs blocks
    for i = 1:num_pwm_out_blocks
      % obtain the pwm module parameter value
      maskValuesCurrent = get_param(pwm_out_blocks(i), 'MaskValues');
      % extract the timer module, which is formated as TIMx
      timerCurrent = strtok(maskValuesCurrent{1}{1}, ':');
      % now loop through the quad encoder blocks to see if this one is already used elsewhere
      for j = 1:num_timer_in_blocks
        % obtain the pwm module parameter value
        maskValuesCheck = get_param(timer_in_blocks(j), 'MaskValues');
        % extract the timer module, which is formated as TIMx
        timerCheck = strtok(maskValuesCheck{1}{1}, ':');
        % check if the mask string for the output pin are the same
        if strcmp(timerCurrent, timerCheck) == 1
          message = strcat('Error: A Timer Input IRQ block for the same timer (', timerCurrent, ') is already present in the model. Select a different timer or remove the Timer Input IRQ block.');
          errordlg(message, 'Block error');
          % no need to continue because error was encountered
          return;
        end
      end
    end
  end
  % now check if a configured timer module for a PWM output is not already used in a timer outputs module.
  num_timer_out_blocks = length(find_system(bdroot, 'MaskType', 'Output Compare Init'));
  % only need to check if there is at least one of each
  if (num_timer_out_blocks > 0) && (num_pwm_out_blocks > 0)
    % store blocks in array
    pwm_out_blocks = find_system(bdroot, 'MaskType', 'Pulse Width Modulation Initialization');
    timer_out_blocks = find_system(bdroot, 'MaskType', 'Output Compare Init');
    % loop through all pwm outputs blocks
    for i = 1:num_pwm_out_blocks
      % obtain the pwm module parameter value
      maskValuesCurrent = get_param(pwm_out_blocks(i), 'MaskValues');
      % extract the timer module, which is formated as TIMx
      timerCurrent = strtok(maskValuesCurrent{1}{1}, ':');
      % now loop through the Output Compare Init blocks to see if this one is already used elsewhere
      for j = 1:num_timer_out_blocks
        % obtain the module parameter value
        maskValuesCheck = get_param(timer_out_blocks(j), 'MaskValues');
        % extract the timer module, which is formated as TIMx
        timerCheck = strtok(maskValuesCheck{1}{1}, ':');
        % check if the mask string for the output pin are the same
        if strcmp(timerCurrent, timerCheck) == 1
          message = strcat('Error: A Output Compare Init block for the same timer (', timerCurrent, ') is already present in the model. Select a different timer or remove the Output Compare Init block.');
          errordlg(message, 'Block error');
          % no need to continue because error was encountered
          return;
        end
      end
    end
  end
end

%%******************************* end of sfcn_pwm_init_chk.m *****************************
